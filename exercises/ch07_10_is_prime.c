/* This program returns 1 if a number is prime and 0 if it is not*/
#include <stdio.h>

int is_prime(int val) {
  if (val % 2 == 0)
    return 0;
  else {
    for (int j = 3; j * j <= val; j += 2)
      if (val % j == 0)
        return 0;

    return 1;
  }
}

int main(void) {
  int val, result;

  printf("Please enter a number to check if it is prime: ");
  scanf("%d", &val);

  result = is_prime(val);

  if (result == 0)
    printf("%i is not prime\n", val);
  else
    printf("%i is prime\n", val);

  return 0;
}
