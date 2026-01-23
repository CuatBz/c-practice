/* These are my custom string functions */
#include "strings.h"
#include <stdio.h>

// Function to read input and replace next line
void readLine(char buf[], int buf_size) {
  int c;
  int count = 0;

  do {
    c = getchar();
    if (c == EOF)
      break;

    buf[count++] = (char)c;
  } while (c != '\n' && count < buf_size - 1);

  buf[count] = '\0';
}
