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

  // Create a semaphore
  sem_t *sem = mem + 0;
  if (sem_init(sem, 1, 0) == -1) {
    perror("sem_init");
  }

  // Wait for the other process to post to the semaphore
  printf("Waiting for the client to `sem_post()`.\n");
  sem_wait(sem);
  printf("Semaphore signal received.\n");

  // Destroy the semaphore
  sem_destroy(sem);

  // Cleanup
  munmap(mem, 4096);
  close(fd);
  shm_unlink("/dev/shm/mmap_example");
}
