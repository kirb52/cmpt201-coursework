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
  ssize_t numchar;

  printf("Hello, Please enter a small sentence \n");

  // gets the input and saves it to numchr
  numchar = getline(&buffer, &size, stdin);

  // error prevention for the list of char if the getline returns a -1
  if (numchar == -1) {
    perror("getline failure");
    free(buffer);
    exit(EXIT_FAILURE);
  }

  // Prints token
  printf("\nToken:\n");

  // gets the first token to print and uses saveptr to know it it left off
  token = strtok_r(buffer, " ", &saveptr);

  // a while loop that loops through the string and seperates it with " "
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(buffer);
}

// TO DO:
// 1) get print to work DONE
// 2) get getline() to take in a string DONE
// 3) figure out how strtok_r() works DONE
// 4) get the tokens to print DONE
// 5) set up error prevention DONE
// hand in?
