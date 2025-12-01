/* This program divides two numbers and prints result to 3 decimal places */
#include <stdio.h>

int main(void) {
  int num1, num2;
  float result;

  printf("Please enter two numbers to divide: ");
  scanf("%i %i", &num1, &num2);

  if (num2 == 0)
    printf("Cannot divide by zero.\n");
  else
    printf("%i divided by %i is %.3f\n", num1, num2, (float) num1 / num2);

  return 0;
}
