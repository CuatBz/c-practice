/* This program raises an integer to a given power */
#include <stdio.h>

long int x_to_the_n(int x, int n) {
  long int result = x;

  for (int j = 1; j < n; j++)
    result *= x;

  return result;
}

int main(void) {
  int x, n;

  printf("Enter a base: ");
  scanf("%i", &x);

  printf("Enter the power: ");
  scanf("%i", &n);

  printf("%i to the power of %i is %li\n", x, n, x_to_the_n(x, n));

  return 0;
}
