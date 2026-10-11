#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *buffer = NULL;
  size_t size = 0;

  while (1) {
    // gets input from user
    printf("Enter programs to run: \n");
    ssize_t input = getline(&buffer, &size, stdin);

    // checks for input error
    if (input == -1) {
      perror("get line failure");
      free(buffer);
      exit(EXIT_FAILURE);
    }

    // removes the \n off of the back of the buffer
    char *program = strtok(buffer, "\n");

    pid_t pid = fork();

    // if pid = -1 the fork has faild
    if (pid == -1) {
      exit(EXIT_FAILURE);
    }
    // if pid = 0 the fork is the child program
    if (pid == 0) {
      execlp(program, program, NULL);
      perror("Exec failure");
      exit(EXIT_FAILURE);
    } else {
      // this is where pid = 1 which is the parent program of the fork
      if (waitpid(pid, NULL, 0) == -1) {
        perror("waitpid failure");
        exit(EXIT_FAILURE);
      }
    }
    free(buffer);

    // user input and print to screen DONE
    // tokenize it DONE
    // figure out what execlp does and implement DONE
    // fix fork DONE
    // figure out waitpid and where to put it DONE
    // loop it DONE
  }
}
