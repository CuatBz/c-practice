// This program prints colums from a given range
#include <stdio.h>

#define BUF_SIZE 1024

int printColumns(char fileName[], int m, int n);

int main(void) {
  char file_name[64];
  int result, m, n;

  printf("Please enter the name of the file:\n");
  scanf("%63s", file_name);

  printf("\nPlease enter the starting column number (starts from zero):\n");
  scanf("%i", &m);

  printf("\nPlease enter the ending column number\n");
  scanf("%i", &n);

  result = printColumns(file_name, m, n);

  return result;
}

int printColumns(char fileName[], int m, int n) {
  FILE *file;
  char *line, buffer[BUF_SIZE];
  int i;

  if (m < 0 || n < 0) {
    fprintf(stderr, "\nColumn values cannot be negative\n");
    return 1;
  }

  // check to make sure n is greater than m
  if (n < m) {
    int temp = m;
    m = n;
    n = temp;
  }

  if ((file = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "\nError accessing file: %s\n", fileName);
    return 2;
  }

  while ((line = fgets(buffer, BUF_SIZE, file)) != NULL) {
    for (i = m; i <= n; i++) {
      if (buffer[i] == '\n')
        break;

      putc(buffer[i], stdout);
    }
    printf("\n");
  }

  return 0;
}
