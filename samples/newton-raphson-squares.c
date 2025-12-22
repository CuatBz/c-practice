/* This program uses the Newton-Raphson method to calculate squares */
#include <stdio.h>

// function to calculate the absolute value of a number
float absoluteValue(float x) {
  if (x < 0)
    x = -x;

  return x;
}

// function to compute the square root of a number
float squareRoot(float x) {
  const float epsilon = 0.00001;
  float guess = 1.0;

  while (absoluteValue(guess * guess - x) >= epsilon) {
    // printf("Current guess: %g\n", guess);
    guess = (x / guess + guess) / 2.0;
  }

  return guess;
}

int main(void) {
  printf("squareRoot (2.0) = %f\n", squareRoot(2.0));
  printf("squareRoot (144.0) = %f\n", squareRoot(144.0));
  printf("squareRoot (54.0) = %f\n", squareRoot(54.0));
  printf("squareRoot (17.5.0) = %f\n", squareRoot(17.5));

  return 0;
}
