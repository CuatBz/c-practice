/* This program generates primes with certain improvements */
#include <stdio.h>

int main(void) {
  int p, d, count = 0;
  _Bool isPrime;

  for (p = 2; p <= 50; ++p) {
    if (p != 2 && (p % 2 == 0))
      continue;
    isPrime = 1;

    for (d = 2; d < p && isPrime != 0; ++d, ++count)
      if (p % d == 0)
        isPrime = 0;

      if (isPrime != 0)
        printf("%i ", p);
  }
  printf("\n%i loops ran\n", count);

  printf("\n");
  return 0;
}
