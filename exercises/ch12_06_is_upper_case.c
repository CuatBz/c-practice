// This program uses a macro to check if a character is uppercase
#include <stdio.h>

#define IS_UPPER_CASE(c) ((((c) >= 'A') && ((c) <= 'Z')) ? 1 : 0)

int main(void) {
  char text[] = "ThiS is ThE teSt teXt";
  char c;
  int index = 0;

  c = text[index];

  while (c) {
    (IS_UPPER_CASE(c) == 0) ? printf("%c is not upper case\n", c)
                            : printf("%c is upper case\n", c);
    c = text[++index];
  }

  return 0;
}
