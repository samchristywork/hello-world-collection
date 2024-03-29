#include <epoxy/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <gtk/gtk.h>

GLuint buffer;
GLuint program;
glm::mat4 model = glm::mat4(1.0);
float speed = 1;

const GLfloat vertices[] = {
    1, -1, -1, 0, -1, 0, 1, -1, 1, 0, -1, 0, -1, -1, 1, 0, -1, 0, 1, -1, -1, 0,
    -1, 0, -1, -1, 1, 0, -1, 0, -1, -1, -1, 0, -1, 0, -1, 1, 1, 0, 1, 0, 1, 1, 1,
    0, 1, 0, 1, 1, -1, 0, 1, 0, -1, 1, 1, 0, 1, 0, 1, 1, -1, 0, 1, 0, -1, 1, -1,
    0, 1, 0, -1, -1, -1, -1, 0, 0, -1, -1, 1, -1, 0, 0, -1, 1, -1, -1, 0, 0, -1,
    -1, 1, -1, 0, 0, -1, 1, 1, -1, 0, 0, -1, 1, -1, -1, 0, 0, -1, -1, 1, 0, 0, 1,
    1, -1, 1, 0, 0, 1, -1, 1, 1, 0, 0, 1, 1, -1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
    -1, 1, 1, 0, 0, 1, 1, 1, -1, 0, 0, -1, 1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0,
    -1, 1, 1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, 1, -1, 0, 0, -1, 1, 1, 1,
    1, 0, 0, 1, -1, 1, 1, 0, 0, 1, -1, -1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, -1, -1,
    1, 0, 0, 1, 1, -1, 1, 0, 0};

GLuint init_shader(int type) {

  GLuint shader = glCreateShader(type);

  if (type == GL_FRAGMENT_SHADER) {
    FILE *f = fopen("shaders/fragment.sl", "rb");
    fseek(f, 0, SEEK_END);
    size_t s = ftell(f);
    rewind(f);
    char *buf = (char *)malloc(s + 1);
    bzero(buf, s + 1);
    fread(buf, 1, s, f);
    glShaderSource(shader, 1, &buf, NULL);
    fclose(f);
  }

  if (type == GL_VERTEX_SHADER) {
    FILE *f = fopen("shaders/vertex.sl", "rb");
    fseek(f, 0, SEEK_END);
    size_t s = ftell(f);
    rewind(f);
    char *buf = (char *)malloc(s + 1);
    bzero(buf, s + 1);
    fread(buf, 1, s, f);
    glShaderSource(shader, 1, &buf, NULL);
    fclose(f);
  }

  glCompileShader(shader);

  int status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

  return shader;
}

void init_shaders(GLuint *program) {
  GLuint vertex, fragment;

  vertex = init_shader(GL_VERTEX_SHADER);
  fragment = init_shader(GL_FRAGMENT_SHADER);

  *program = glCreateProgram();
  glAttachShader(*program, vertex);
  glAttachShader(*program, fragment);

  glLinkProgram(*program);

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void realize(GtkWidget *widget) {
  gtk_gl_area_make_current(GTK_GL_AREA(widget));

  glGenVertexArrays(1, &buffer);
  glBindVertexArray(buffer);

  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  init_shaders(&program);

  glEnable(GL_CULL_FACE);
  glFrontFace(GL_CCW);
  glCullFace(GL_BACK);
  glEnable(GL_DEPTH_TEST);
}

void draw(GLuint program) {
  glUseProgram(program);

  glm::vec3 position = glm::vec3(0, 0, 5);
  glm::vec3 front = glm::vec3(0, 0, -1);
  glm::vec3 up = glm::vec3(0, 1, 0);

  model = rotate(model, speed * .01f, glm::vec3(1, 1, 1));
  glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, &model[0][0]);

  glm::mat4 view = glm::lookAt(position, position + front, up);
  glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, &view[0][0]);

  double aspect_ratio = 1;
  glm::mat4 projection = glm::perspective(45.0, aspect_ratio, 0.1, 100.0);
  glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, &projection[0][0]);

  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glDrawArrays(GL_TRIANGLES, 0, 36);

  glDisableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glUseProgram(0);
}

gboolean render(GtkGLArea *area, GdkGLContext *context) {

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  draw(program);

  gtk_gl_area_queue_render(area);
  return TRUE;
}

gboolean keypress_callback(GtkWidget *widget, GdkEventKey *event, gpointer data) {

  if (event->keyval == GDK_KEY_Escape) {
    exit(EXIT_SUCCESS);
    return TRUE;
  }
  return FALSE;
}

void button_callback() {
  if (speed) {
    speed = 0;
  } else {
    speed = 1;
  }
  printf("Hello, World!\n");
}

int main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  // Main window
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "OpenGL Test");

  // Boxes
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, FALSE);
  gtk_container_add(GTK_CONTAINER(window), box);

  // Drawing area
  GtkWidget *gl_area = gtk_gl_area_new();
  gtk_box_pack_start(GTK_BOX(box), gl_area, 1, 1, 0);

  // Button
  GtkWidget *button = gtk_button_new_with_label("Hello, World!");
  g_signal_connect(button, "clicked", G_CALLBACK(button_callback), NULL);
  gtk_widget_set_name(button, "myButton");
  gtk_container_add(GTK_CONTAINER(box), button);

  // CSS
  GtkCssProvider *css = gtk_css_provider_new();
  gtk_css_provider_load_from_path(css, "style.css", NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(css), GTK_STYLE_PROVIDER_PRIORITY_USER);

  // Signals
  g_signal_connect(gl_area, "realize", G_CALLBACK(realize), NULL);
  g_signal_connect(gl_area, "render", G_CALLBACK(render), NULL);

  // Events
  gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
  g_signal_connect(G_OBJECT(window), "key_press_event", G_CALLBACK(keypress_callback), NULL);

  // Main loop
  gtk_widget_show_all(GTK_WIDGET(window));
  gtk_main();
}
