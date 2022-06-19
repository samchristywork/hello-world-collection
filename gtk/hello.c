#include <gtk/gtk.h>
#include <math.h>

int counter = 0;
GtkWidget *drawingArea;

/*
 * Called every time a button is pressed
 */
static void buttonCallback(GtkButton *button, gpointer userData) {
  counter++;
  g_print(userData);
  gdk_window_invalidate_rect(gtk_widget_get_window(drawingArea), NULL, TRUE);
}

/*
 * Called every time a key is pressed
 */
gboolean keyPressCallback(GtkWidget *widget, GdkEventKey *event,
                          gpointer data) {

  /*
   * Exit when the user presses Escape
   */
  if (event->keyval == GDK_KEY_Escape) {
    exit(EXIT_SUCCESS);
    return TRUE;
  }
  return FALSE;
}

/*
 * Called every time a redraw is requested for the drawing area
 */
gboolean drawCallback(GtkWidget *widget, cairo_t *cr, gpointer data) {

  GtkStyleContext *context = gtk_widget_get_style_context(widget);

  guint width = gtk_widget_get_allocated_width(widget);
  guint height = gtk_widget_get_allocated_height(widget);

  GdkRGBA color;
  gtk_render_background(context, cr, 0, 0, width, height);
  gtk_style_context_get_color(context, gtk_style_context_get_state(context),
                              &color);

  /*
   * Draw text
   */
  char buf[256];
  snprintf(buf, 255, "%d", counter);
  cairo_move_to(cr, width / 2, height / 2);
  cairo_set_font_size(cr, 20);
  gdk_cairo_set_source_rgba(cr, &color);

  /*
   * We can also set color like this:
   */
  // cairo_set_source_rgba(cr, 1,0,0,1);

  cairo_show_text(cr, buf);
  cairo_fill(cr);

  /*
   * Draw arc
   */
  cairo_arc(cr, width / 2, height / 2, width / 2, 0, 2 * M_PI * counter / 64);
  gdk_cairo_set_source_rgba(cr, &color);
  cairo_stroke(cr);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // box
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add(GTK_CONTAINER(window), box);

  // button
  GtkWidget *button = gtk_button_new_with_label("Increment Counter");
  g_signal_connect(button, "clicked", G_CALLBACK(buttonCallback),
                   "Hello, World!\n");
  gtk_container_add(GTK_CONTAINER(box), button);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // Drawing area
  drawingArea = gtk_drawing_area_new();
  gtk_widget_set_size_request(drawingArea, 200, 200);
  g_signal_connect(G_OBJECT(drawingArea), "draw", G_CALLBACK(drawCallback),
                   NULL);
  gtk_container_add(GTK_CONTAINER(box), drawingArea);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Hello, World!");

  // Events
  gtk_widget_add_events(window, GDK_KEY_PRESS_MASK);
  g_signal_connect(G_OBJECT(window), "key_press_event",
                   G_CALLBACK(keyPressCallback), NULL);

  gtk_widget_show_all(window);
  gtk_main();
}
