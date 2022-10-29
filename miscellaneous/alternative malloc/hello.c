#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 10;
  char *str = malloc(n);
  for (int i = 0; i < n; i++) {
    printf("str[%d] = %d\n", i, str[i]);
  }
  free(str);
}
