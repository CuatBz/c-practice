// This program tests interchanging two numbers with XOR
#include <stdio.h>

void swapInts(int *num1, int *num2);

int main(void) {
  int num1 = 32, num2 = 52;

  printf("num1: %i | num2: %i\n", num1, num2);

  swapInts(&num1, &num2);
  printf("num1: %i | num2: %i\n", num1, num2);

  return 0;
}

void swapInts(int *num1, int *num2) {
  *num1 ^= *num2;
  *num2 ^= *num1;
  *num1 ^= *num2;
}
