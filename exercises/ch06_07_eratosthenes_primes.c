/* This program will generate primes using Eratosthenes algorithm */
#include "stdio.h"

#define LEN 150

int main(void) {
  int vals[LEN], cont = 0, i, j, position;

  // Initialize values for array
  for (i = 0; i < LEN; ++i)
    vals[i] = 0;

  i = 2;
  j = 2;
  position = 1;
  while (cont == 0) {
    while (j * i <= LEN) {
      vals[(i * j) - 1] = 1;
      ++j;
    }

    for (int b = position; b <= LEN; ++b) {
      if ((b > (i - 1)) && vals[b] == 0) {
        i = b + 1;
        position = b;
        j = 2;
        break;
      } else if (b == LEN) {
        cont = 1;
      }
    }
  }

  for (j = 0; j < LEN; j++) {
    if (vals[j] == 0)
      printf("%i ", j + 1);
  }

  printf("\n");
  return 0;
}
