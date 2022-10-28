#include <stdio.h>

ssize_t write(int fd, const void *buf, size_t count) {
  printf("Writing %d char(s) to file descriptor %d\n", count ,fd);
  FILE *f = fdopen(fd, "w");
  fwrite(buf, 1, count ,f);
  fclose(f);
}
