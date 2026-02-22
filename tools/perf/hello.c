#include <stdio.h>

int main(void) {
  long sum = 0;
  for (long i = 0; i < 1000000000L; i++) {
    sum += i;
  }
  printf("Hello, World! (sum=%ld)\n", sum);
  return 0;
}
