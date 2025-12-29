/* Program to sort an array of integers into ascending/descending order */
#include <stdio.h>

void sort(int a[], int n, int order) {
  int i, j, temp;

  if (order == 1) {
    for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n; ++j)
        if (a[i] > a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
  } else if (order == 2) {
    for (i = 0; i < n - 1; ++i)
      for (j = i + 1; j < n; ++j)
        if (a[i] < a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
  }
}

void printArray(int vals[], int arr_size) {
  int i;

  for (i = 0; i < arr_size; ++i)
    printf("%i ", vals[i]);

  printf("\n");
}

int main(void) {
  int array[16] = {34, -5, 6,  0,  12, 100, 56, 22,
                   44, -3, -9, 12, 17, 22,  6,  11};

  printf("The array before the ascending sort:\n");
  printArray(array, 16);

  sort(array, 16, 1);

  printf("\n\nThe array after the sort:\n");
  printArray(array, 16);

  printf("\n\nThe array before the descending sort:\n");
  printArray(array, 16);

  sort(array, 16, 2);

  printf("\n\nThe array after the sort:\n");
  printArray(array, 16);

  printf("\n");

  return 0;
}
