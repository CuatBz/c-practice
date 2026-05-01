// This porgram does some bit shifting to the left if the value is positive
// and to the right if it's negative
#include <stdio.h>

#define SHIFT(amnt, val) (amnt < 0) ? (val >> (-1 * amnt)) : (val << amnt)

int main(void) {
  unsigned int num = 34634;

  printf("%i left shifted by 1 is %i\n", num, SHIFT(1, num));

  printf("\n%i right shifted by 2 is %i\n", num, SHIFT(-2, num));

  return 0;
}
