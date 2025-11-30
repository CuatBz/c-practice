/* This program prints the square of 10 numbers */
#include <stdio.h>

int main(void) {
  printf("Value        Square\n");
  for (int i = 1; i <= 10; i++) {
    
    printf(" %2i          %3i\n", i, i * i);
  }
  return 0;
}
