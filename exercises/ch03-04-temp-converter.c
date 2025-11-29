/* Program that converts from farenheit to celsius */
#include <stdio.h>

int main(void) {
  float farenheit, celsius, result;
  farenheit = 27;

  result = (farenheit - 32) / 1.8;

  printf("%g farenheit is equals to %g celsius.\n", farenheit, result);
  
  return 0;
}

