/* This program evaluates an expression that has exponents */
#include <stdio.h>

int main(void) {
    float result = (3.31e-8 * 2.01e-7) / (7.16e-6 + 2.01e-8);

    printf("(3.31 x 10^-8 x 2.01 x 10^-7) / (7.16 x 10^-6 + 2.01 x 10^-8) = %g",
           result);
    return 0;
  }
