// This program reads from the terminal using pointers
#include <stdio.h>

#define SIZE 81

void readLine(char *buffer);

int main(void) {
  char buffer[SIZE];

  for (int i = 0; i < 3; ++i) {
    readLine(buffer);
    printf("%s\n\n", buffer);
  }

  return 0;
}

void readLine(char *buffer) {
  char c;

  do {
    c = getchar();
    *buffer++ = c;
  } while (c != '\n');
  *--buffer = '\0';
}
