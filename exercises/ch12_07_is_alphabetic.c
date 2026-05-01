// This program uses macros to verify if a character is alphabetic
#include <stdio.h>

#define IS_UPPER_CASE(c) ((((c) >= 'A') && ((c) <= 'Z')) ? 1 : 0)
#define IS_LOWER_CASE(c) ((((c) >= 'a') && ((c) <= 'z')) ? 1 : 0)
#define IS_ALPHA(c)                                                            \
  (((IS_UPPER_CASE(c) == 1) || (IS_LOWER_CASE(c) == 1)) ? 1 : 0)

int main(void) {
  char text[] = "THis is 534 our te35st te1xt.", c;
  int index = 0;

  c = text[index];

  while (c) {
    (IS_ALPHA(c) == 0) ? printf("%c is not alphabetic\n", c)
                       : printf("%c is alphabetic\n", c);
    c = text[++index];
  }

  return 0;
}
