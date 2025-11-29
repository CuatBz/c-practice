/* Program that shows how for loops can be nested */
#include <stdio.h>

int main(void) {
  int n, number, triangularNumber, counter;

  for (counter = 1; counter <= 5; ++counter) {
    printf("What trinagular number do you want? ");
    scanf("%i", &number);

    triangularNumber = 0;

    for (n = 1; n <= number; ++n)
      triangularNumber += n;

    printf("Triangular number %i is %i\n\n", number, triangularNumber);
  }

  return 0;
}
