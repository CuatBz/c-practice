// This program uses a macro to calculate absolute value
#include <stdio.h>

#define ABSOLUTE(x) ((x < 0) ? (x * -1) : x)

int main(void) {
  int a = 12, b = -32, c = 0;

  printf("The absolute value of %i is %i\n", a, ABSOLUTE(a));
  printf("\nThe absolute value of %i is %i\n", b, ABSOLUTE(b));
  printf("\nThe absolute value of %i is %i\n", c, ABSOLUTE(c));

  return 0;
}
