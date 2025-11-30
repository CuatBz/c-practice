/* This program prints out every fifth triangular number */
#include <stdio.h>

int main(void) {
  int result;

  printf("Number            Triangular Number\n");
  for (int i = 5; i <= 50; i += 5) {
    result = i * (i + 1) / 2;
    printf("%3i                    %-4i\n", i, result);
  }
  return 0;
}
