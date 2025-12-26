/* This program calculates a triangular number in a function and returns it */
#include <stdio.h>

int calculateTriangularNumber(int n) {
  int i, triangularNumber = 0;

  for (i = 1; i <= n; ++i)
    triangularNumber += i;

  return triangularNumber;
}

int main(void) {
  int j;

  for (j = 5; j <= 20; j += 5)
    printf("Number: %2i, Triangular number: %5i\n", j,
           calculateTriangularNumber(j));

  return 0;
}
