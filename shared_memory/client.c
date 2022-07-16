#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

struct example_struct{
  int i;
  float f;
};

int main() {

  // Open the shm file
  int fd = open("/dev/shm/mmap_example", O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  // Map the file into memory
  void *mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // Test referencing a string from the shared memory region
  char *buffer=mem+0;
  printf("String: %s\n", buffer);

  // Test referencing an int
  int *i=mem+20;
  printf("Int:    %d\n", *i);

  // Test referencing a struct
  struct example_struct *k=mem+24;
  printf("Struct: %d\n", k->i);
  printf("        %f\n", k->f);

  // Cleanup
  munmap(mem, 4096);
  close(fd);
}
