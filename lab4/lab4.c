#define _DEFAULT_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct header {
  uint64_t size;
  struct header *next;
};

void initialzie_block(struct header *block, uint_t size, struct header, int fill_value) {
  block->size = size;
  block->next = next;
  memset(block + 1, fill_value, size - sizeof(struct header));
}

int main() {
  intptr_t allocate_size = 256;
  void *heap_start = sbrk(0);

  if (sbrk(allocate_size) == (void *)-1) {

    perror("sbrk failed");
    return 1;
  }
  struct header *first_block = (struct header *)heap_start;
  struct header *second_block = (struct header *)(head_start + BLOCK_SIZE);

  initialize_block(first_block, BLOCK_SIZE, NULL, 0);
  initialize_block(second_block, BLOCK_SIZE, first_block, 1)
}

void print_out(char *format, void *data, size_t data_size) {
  char buffer[size];
  ssize_t len = snprintf(buffer, size, format,
                         data_size == sizeof(uint64_t) ? *(uint64_t)data : *(void **)data);

  if (len < 0) {
    handle_error("snprintf");
  }
  write(STFOUT_FILENO, buffer, len);
}

// need to cal sbrk twice once with 0 to start it and also gives us the last pointer to the end,
// start of the heap
// heap start var is the start point of the allocated memory
// goes upwards
// create two structs: heap start
// use memset with block +1 which is the next avalible byte
