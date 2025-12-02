/* This program prints each digit in a number as a word */
#include <stdio.h>

int main(void) {
  int number, digit, digit_count = 0, temp;

  printf("Please enter a digit you want to see in words: ");
  scanf("%i", &number);

  temp = number;

  // Find how many digits are in the number
  do {
    temp /= 10;
    ++digit_count;
  }
  while (temp != 0);

  for (int i = digit_count; i > 0; --i) {
    temp = number;

    // Get to the left most digit for current loop
    for (int j = 1; j < i; ++j) {
      temp = temp / 10;
    }
    digit = temp % 10;    // take only the right most digit

    switch(digit) {
      case 0:
        printf("zero ");
        break;

      case 1:
        printf("one ");
        break;

      case 2:
        printf("two ");
        break;

      case 3:
        printf("three ");
        break;

      case 4:
        printf("four ");
        break;

      case 5:
        printf("five ");
        break;

      case 6:
        printf("six ");
        break;

      case 7:
        printf("seven ");
        break;

      case 8:
        printf("eight ");
        break;

      case 9:
        printf("nine ");
        break;

      default:
        printf("invalid ");
        break;
    }
  }
  printf("\n");

  return 0;
}
