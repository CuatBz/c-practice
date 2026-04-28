// This program creates a MIN macro
#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
  int a = 5, b = 3;

  printf("Minimum of %i and %i is %i\n", a, b, MIN(a, b));

  return 0;
}
