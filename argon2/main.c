#include "argon2.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  int memory = (1 << 20);
  int parallelism = 1;
  int salt_len = 16;
  int hash_len = 32;
  int iterations = 3;

  char *password = "changeme";
  char salt[salt_len];
  unsigned char hash[hash_len];

  memset(salt, 0x00, salt_len);
  sprintf(salt, "salt");

  fprintf(stderr, "Generating Argon2 hash:\n");
  argon2i_hash_raw(iterations, memory, parallelism, password, strlen(password),
                   salt, salt_len, hash, hash_len);

  write(STDOUT_FILENO, hash, hash_len);
  fprintf(stderr, "\n");
}
