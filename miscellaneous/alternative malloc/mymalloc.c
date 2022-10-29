#include <stdio.h>
#include <unistd.h>

typedef struct free_block {
  size_t size;
  struct free_block *next;
} free_block;

static free_block free_block_list_head = {0, 0};
static const size_t overhead = sizeof(size_t);
static const size_t align_to = 16;

void *malloc(size_t size) {

  size = (size + sizeof(size_t) + (align_to - 1)) & ~(align_to - 1);
  free_block *block = free_block_list_head.next;
  free_block **head = &(free_block_list_head.next);
  while (block != 0) {
    if (block->size >= size) {
      *head = block->next;
      return ((char *)block) + sizeof(size_t);
    }
    head = &(block->next);
    block = block->next;
  }

  block = (free_block *)sbrk(size);
  block->size = size;

  char *p = ((char *)block) + sizeof(size_t);
  for (int i = 0; i < block->size; i++) {
    p[i] = 'a';
  }

  return ((char *)block) + sizeof(size_t);
}

void free(void *ptr) {
  printf("Freeing block.\n");
  free_block *block = (free_block *)(((char *)ptr) - sizeof(size_t));
  block->next = free_block_list_head.next;
  free_block_list_head.next = block;
}
