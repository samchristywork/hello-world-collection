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

  // Open the shm file and set the size
  int fd = open("/dev/shm/mmap_example", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }
  ftruncate(fd, 4096);

  // Map the file into memory
  void *mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (mem == MAP_FAILED) {
    perror("mmap");
    exit(EXIT_FAILURE);
  }

  // Test writing a string to the shared memory region
  char *buffer=mem+0;
  sprintf(buffer, "Hello, World!");

  // Test writing an int
  int i=99;
  memcpy(mem+20, &i, sizeof(i));

  // Test writing a struct
  struct example_struct t={
    .i=66,
    .f=1.234,
  };
  memcpy(mem+24, &t, sizeof(t));

  // Wait for user input
  printf("Started server, press Enter to close.\n");
  getchar();

  // Cleanup
  munmap(mem, 4096);
  close(fd);
  shm_unlink("/dev/shm/mmap_example");
}
