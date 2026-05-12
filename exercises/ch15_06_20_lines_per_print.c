// This program displays a text file 20 lines at a time
#include <stdio.h>

#define BUF_SIZE 1024

int printLines(char fileName[]);

int main(void) {
  int result, c;
  char fileName[64];

  printf("Please enter the file name:\n");
  scanf("%63s", fileName);

  result = printLines(fileName);

  return result;
}

int printLines(char fileName[]) {
  FILE *text;
  char *line, buffer[BUF_SIZE];
  int opt;

  if ((text = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "\nError accessing file: %s\n", fileName);
    return 1;
  }

  do {
    while ((opt = getchar()) != '\n' && opt != EOF)
      ;

    printf("\nPlease enter 'n' to print the next 20 lines, or 'q' to quit:\n");
    scanf(" %c", &opt);

    printf("\nOption is %c\n", opt);

    if (opt == 'n') {
      for (int i = 0; i < 20; i++) {
        line = fgets(buffer, BUF_SIZE, text);

        if (line == NULL) {
          printf("\nEnd Of File reached. Terminating.\n");
          return 0;
        } else {
          fprintf(stdout, "%s", buffer);
        }
      }
    } else if (opt == 'q') {
      printf("\nQuitting...\n");
      fclose(text);
      continue;
    } else {
      printf("\nInvalid option. Please try again.");
    }

  } while (opt != 'q');

  return 0;
}
