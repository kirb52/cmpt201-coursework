#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  // set the buffer to null so getline will set the buffer
  size_t size = 0;
  char *token;
  char *saveptr;

  printf("Hello, Please enter a small sentence \n");

  getline(&buffer, &size, stdin);

  printf("\nToken:\n");

  token = strtok_r(buffer, " ", &saveptr);

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(buffer);
}

// TO DO:
// 1) get print to work DONE
// 2) get getline() to take in a string DONE
// 3) figure out how strtok_r() works
// 4) get the tokens to print
// 5) set up error prevention
// hand in?
