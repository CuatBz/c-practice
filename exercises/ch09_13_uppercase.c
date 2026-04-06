// This program converts all lowercase ASCII chars to uppercase
#include "my_strings.h"
#include <stdio.h>

void uppercase(char s[]);

int main(void) {
  char input[256];

  printf("Please enter some text with upper and lower case letters: ");
  nl_readLine(input, 256);

  uppercase(input);

  printf("\nText is now:\n%s\n", input);

  return 0;
}

void uppercase(char s[]) {
  int index = 0;

  while (s[index] != '\0') {
    if (s[index] >= 'a' && s[index] <= 'z')
      s[index] = s[index] - 'a' + 'A';

    index++;
  }
}
