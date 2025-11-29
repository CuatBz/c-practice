/* Program that rounds off an integer i to the next largest even multiple 
    of another integer j */
#include <stdio.h>

int main(void) {
  int i, j, result;
  i = 365, j = 7;
  result = (i + j) - (i % j);

  printf("%i + %i = %i\n", i, j, i + j);
  printf("%i %% %i = %i\n", i, j, i % j);
  printf("i = %i, j = %i\n", i, j);
  printf("Next multiple for %i with %i is %i\n", j, i, result);

  return 0;
  }
