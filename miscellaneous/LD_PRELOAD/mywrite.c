#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count) {
  printf("Writing %zu char(s) to file descriptor %d\n", count, fd);
  return syscall(SYS_write, fd, buf, count);
}
