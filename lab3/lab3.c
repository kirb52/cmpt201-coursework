#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  size_t size = 0;
  char *words[5];
  char *buffer = NULL;
  int count = 0;

  while (1) {
    // asks for input
    printf("Please enter an input: \n");
    ssize_t input = getline(&buffer, &size, stdin);

    // error prevention
    if (input == -1) {
      break;
    }

    // if the buffer is = to "print" prints all the words in the array
    if (strcmp(buffer, "print\n") == 0) {
      for (int i = 0; i < count; i++) {
        printf("%s", words[i]);
      }
      continue;
    }

    // if the buffer is blank it ignores it and outputs "blank"
    if (strcmp(buffer, "\n") == 0) {
      printf("Blank!\n");
      continue;
    }

    // if the count is smaller than 5 then allocate space on the array
    if (count < 5) {
      words[count] = malloc(input + 1);
      strcpy(words[count], buffer);
      count++;
    } else {
      // if the count is smaller than 5 then free the first (oldest) word it the array and then sift
      // all of the words down one
      free(words[0]);

      for (int i = 0; i < 4; i++) {
        words[i] = words[i + 1];
      }
    }

    // allocate space for the new buffer
    words[4] = malloc(input + 1);
    strcpy(words[4], buffer);
  }

  // frees the words when the loop is completed
  for (int i = 0; i < count; i++) {
    free(words[i]);
  }

  // frees the buffer when done
  free(buffer);
}
