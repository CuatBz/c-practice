/* A program that prints out the first 10 factorials */
#include <stdio.h>

int main(void) {
  int result = 1;

  printf("Value           Factorial\n");
  for (int i = 1; i <= 10; ++i) {
    result *= i;
    printf("%3i              %7i\n", i, result) ;
  }
  return 0;
}
