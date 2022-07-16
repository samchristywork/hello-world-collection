#include <fcntl.h>
#include <semaphore.h>
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

  // Post to the semaphore in shared memory
  printf("Sending semaphore signal with `sem_post()`.\n");
  sem_t *sem = mem;
  sem_post(sem);

  // Cleanup
  munmap(mem, 4096);
  close(fd);
}
