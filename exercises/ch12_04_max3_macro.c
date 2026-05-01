// This program uses a macro to find the maximum of 3 numbers
#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX3(a, b, c) (((MAX(a, b)) > c) ? (MAX(a, b)) : c)

int main(void) {
  int a = 17, b = 8, c = 27;

  printf("Max of %i, %i and %i is %i\n", a, b, c, MAX3(a, b, c));

  return 0;
}
