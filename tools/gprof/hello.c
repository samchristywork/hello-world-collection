#include <stdio.h>

long fib(int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}

int main(void) {
  printf("Hello, World!\n");
  printf("fib(35) = %ld\n", fib(35));
  return 0;
}
