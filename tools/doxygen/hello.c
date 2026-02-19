/**
 * @file hello.c
 * @brief A simple Hello, World! program demonstrating Doxygen documentation.
 */

#include <stdio.h>

/**
 * @brief Prints a greeting for the given name.
 * @param name The name to greet.
 */
void greet(const char *name) {
  printf("Hello, %s!\n", name);
}

/**
 * @brief Program entry point.
 * @return 0 on success.
 */
int main(void) {
  greet("World");
  return 0;
}
