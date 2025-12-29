/* This program calculates the squares of numbers */
#include <stdio.h>

float absoluteVale(float x) {
  if (x < 0)
    x = -x;

  return x;
}

// Function to compute the square root of a number
float squareRoot(float x, float epsilon) {
  float guess = 1.0;

  while (absoluteVale(x / (guess * guess) - 1) > epsilon)
    guess = (x / guess + guess) / 2.0;

  return guess;
}

int main(void) {
  printf("squareRoot (130) = %f\n", squareRoot(130, 0.1));
  printf("squareRoot (130) = %f\n", squareRoot(130, 0.0001));
  printf("squareRoot (130) = %f\n", squareRoot(2, 0.000001));

  return 0;
}
