/* This program will generate a fibonacci sequence using no arrays */
#include <stdio.h>

int main(void) {
  int prev = 0, curr = 1, next, amount, i;

  printf("How many Fibonacci numbers you would like to generate: ");
  scanf("%d", &amount);

  if (amount < 3) {
    printf("\nUsage: number needs to be greater than 2.\n");
    return 1;
  } else {
    printf("The first %i Fibonacci numbers are:\n", amount);
    printf("%i %i", prev, curr);

    for (i = 2; i < amount; i++) {
      next = prev + curr;
      printf(" %i", next);
      prev = curr;
      curr = next;
    }
  }

  return 0;
}
