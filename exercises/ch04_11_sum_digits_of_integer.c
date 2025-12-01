/* This program adds up the digits contained in an integer */
#include <stdio.h>

int main(void) {
  int sum = 0, digit = 0, input, remainder;

  printf("Please enter an integer: ");
  scanf("%i", &input);

  remainder = input;
  do {
    digit = remainder % 10;
    sum += digit;
    remainder /= 10;
  }
  while (remainder != 0);
  
  printf("The sum of the digits in %i is %i\n", input, sum);

  return 0;
}
