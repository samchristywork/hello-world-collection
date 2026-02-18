#include <stdio.h>
#include <string.h>

void greet(char *name) {
  char buf[10];
  strcpy(buf, name);
  printf("Hello, %s!\n", buf);
}

int main(void) {
  greet("World");
  return 0;
}
