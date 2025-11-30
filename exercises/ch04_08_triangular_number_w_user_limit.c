/* Program that allows user to decide how many triangular #s to calculate */
#include <stdio.h>

int main(void) {
  int n, number, triangularNumber, counter, limit;

  printf("How many triangular numbers do you want to calculate? ");
  scanf("%i", &limit);

  for (counter = 1; counter <= limit; ++counter) {
    printf("What triangular number do you want? ");
    scanf("%i", &number);

    triangularNumber = 0;

    for (n = 1; n <= number; ++n)
      triangularNumber += n;

    printf("Triangular number %i is %i\n\n", number, triangularNumber);
  }

  return 0;
}
