/* Program that makes use of the increment operator */
#include <stdio.h>

int main(void) {
  int triangularNumber = 0;
  for (int n = 1; n <= 10; n++) {
    triangularNumber += n;
    printf(" %2i           %i\n", n, triangularNumber);
  }

  return 0;
}
