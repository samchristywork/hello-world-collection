#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *message = malloc(14);
  sprintf(message, "Hello, World!");
  printf("%s\n", message);
  return 0;
}
