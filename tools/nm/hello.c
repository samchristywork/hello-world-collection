#include <stdio.h>

const char *message = "Hello, World!";

void greet(void) {
  printf("%s\n", message);
}

int main(void) {
  greet();
  return 0;
}
