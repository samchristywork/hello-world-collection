#include <glib.h>
#include <stdio.h>

int main() {
  GList *list = NULL;
  list = g_list_append(list, "Hello, World!");
  printf("%s\n", g_list_first(list)->data);
}
