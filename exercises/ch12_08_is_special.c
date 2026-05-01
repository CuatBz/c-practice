// This program checks if a character is a special symbol
#include <stdio.h>

#define IS_UPPER_CASE(c) ((((c) >= 'A') && ((c) <= 'Z')) ? 1 : 0)
#define IS_LOWER_CASE(c) ((((c) >= 'a') && ((c) <= 'z')) ? 1 : 0)
#define IS_ALPHA(c)                                                            \
  (((IS_UPPER_CASE(c) == 1) || (IS_LOWER_CASE(c) == 1)) ? 1 : 0)

#define IS_DIGIT(c) ((((c) >= '0') && ((c) <= '9')) ? 1 : 0)

#define IS_SPECIAL(c) (((IS_ALPHA(c) == 0) && (IS_DIGIT(c) == 0)) ? 1 : 0)

int main(void) {
  char text[] = "tH1s is %t3st t*&xt for #s", c;
  int index = 0;

  c = text[index];

  while (c) {
    (IS_SPECIAL(c) == 1) ? printf("%c is a special character\n", c)
                         : printf("%c is not a special character\n", c);
    c = text[++index];
  }

  return 0;
}
