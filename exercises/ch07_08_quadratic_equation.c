/* This program solves a quadratic equation and informs if the discriminant
 * is less than zero */
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

float discriminant(float a, float b, float c) { return (b * b) - (4 * a * c); }

void solveQuadraticEquation(float a, float b, float c) {
  float disc = discriminant(a, b, c);
  float result;

  printf("Discriminant: %f\n", disc);

  if (disc < 0) {
    printf("\nThe roots are imaginary.\n");
  } else {
    result = (-b + squareRoot(disc, 0.00001)) / (2 * a);
    printf("-b + sqRt(b^2 - 4ac) / 2a = %f\n", result);

    result = (-b - squareRoot(disc, 0.00001)) / (2 * a);
    printf("-b - sqRt(b^2 - 4ac) / 2a = %f\n", result);
  }
}

int main(void) {
  float a, b, c;

  printf("Please enter a, b and c for the quadratic equation: ");
  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);

  solveQuadraticEquation(a, b, c);

  return 0;
}
