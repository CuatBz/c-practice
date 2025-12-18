/* This program calculates the average for a 10 digit array */
#include <stdio.h>

int main(void) {
  int i, input, arr_len = 10;
  float vals[arr_len], sum = 0.0, average;

  printf("Please enter %i numbers to find the average: ", arr_len);
  for (i = 0; i < arr_len; i++)
    scanf("%f", &vals[i]);

  for (i = 0; i < arr_len; i++)
    sum += vals[i];

  average = sum / arr_len;

  printf("\nThe average for the %i numbers is: %g\n", arr_len, average);

  return 0;
}
