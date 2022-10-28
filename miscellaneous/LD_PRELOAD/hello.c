#include <string.h>
#include <unistd.h>

int main() {
  char *str = "Hello, World!\n";
  write(STDOUT_FILENO, str, strlen(str));
}
