/* This program sums an indicated number of integers in an array */
#include <stdio.h>

int array_sum(int array[], int len) {
  int result = 0;

  for (int j = 0; j < len; ++j)
    result += array[j];

  return result;
}

int main(void) {
  int my_array1[] = {11, 15, 12, 25};
  int my_array2[] = {45, 62, 5, 47, 56, 17};

  printf("Sum of array 1 is %i\n", array_sum(my_array1, 4));
  printf("Sum of array 1 is %i\n", array_sum(my_array2, 6));

  return 0;
}
