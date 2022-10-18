#include <gtk/gtk.h>

void clickCallback(GtkButton *button, gpointer data) {
  printf("Hello, World!\n");
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "hello.glade", NULL);

  GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
  GtkWidget *button = GTK_WIDGET(gtk_builder_get_object(builder, "button"));

  gtk_builder_connect_signals(builder, NULL);
  g_signal_connect(G_OBJECT(button), "key-press-event", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(clickCallback), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  g_object_unref(builder);
  gtk_widget_show(window);
  gtk_main();
}
