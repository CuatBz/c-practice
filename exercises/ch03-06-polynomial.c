/* Program that evaluates a polinomial */
#include <stdio.h>

int main(void) {
  float result, x;
  
  x = 2.55;
  result = (3 * (x * x * x)) - (5 * (x * x)) + 6;

  printf("The result of 3x^3 - 5x^2 + 6 = %f\n", result);

  return 0;
}
