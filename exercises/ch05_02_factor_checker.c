/* This program checks if an integer is a factor of another */
#include <stdio.h>

int main(void) {
  int i, j, remainder;

  printf("Please enter two numbers to check if they are factors: ");
  scanf("%i %i", &i, &j);

  remainder = i % j;

  if (remainder == 0)
    printf("%i is a factor of %i\n", j, i);
  else
    printf("%i is not a factor of %i\n", j, i);

  return 0;
}
