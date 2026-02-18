#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *arr = malloc(5 * sizeof(int));

  // Off-by-one: writes to arr[5], one past the end of the allocation.
  for (int i = 0; i <= 5; i++) {
    arr[i] = i;
  }

  printf("Hello, World!\n");
  free(arr);
  return 0;
}
