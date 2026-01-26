/* These are my custom string functions */
#include "strings.h"
#include <stdio.h>

// Function to read input and replace next line
void nl_readLine(char buf[], int buf_size) {
  int c;
  int count = 0;

  /* Read uo to buf_size -1 chars or until newline/EOF */
  while (count < buf_size - 1) {
    c = getchar();
    if (c == EOF || c == '\n')
      break;

    buf[count++] = (char)c;
  }

  buf[count] = '\0';

  // Flush remainder of line
  if (c != '\n' && c != EOF) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
}

/*
 * gcc -Wall -Wextra -c my_strings.c
 * ar rcs libmy_strings.a my_strings.o
 *
 * Then have it pointed from or copied to local/include
 * */

/*
 * Dynamic linking:
 * gcc -Wall -Wextra -c my_strings.c
 * gcc -fPIC -shared my_strings.c -o libmy_strings.so
 * */
