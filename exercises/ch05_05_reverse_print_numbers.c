/* This program prints the digits of an integer in the reverse order
 * including negative numbers */
#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int number, remainder, digit;
  bool isNegative = false;

  printf("Please enter an integer: ");
  scanf("%i", &number);

  if (number < 0) {
    isNegative = true;
    number *= -1;
  }

  do {
    digit = number % 10;
    printf("%i", digit);
    number /= 10;
  }
  while (number != 0);

  if (isNegative)
    printf("-");
  printf("\n");

  return 0;
}
