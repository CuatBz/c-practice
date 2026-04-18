// This program sorts an array making use of pointers
#include <stdio.h>

void sort(int *arr, int len);
void printArray(int *arr, int len);

int main(void) {
  int array[16] = {34, -5, 6,  0,  12, 100, 56, 22,
                   44, -3, -9, 12, 17, 22,  6,  11};

  printArray(array, 16);

  sort(array, 16);

  printf("\nAfter sort:\n");
  printArray(array, 16);

  return 0;
}

void sort(int *arr, int len) {
  int *j = arr, *k;
  int temp;

  while (j < (arr + len - 1)) {
    k = j + 1;
    while (k++ < arr + len) {
      if (*j > *k) {
        temp = *j;
        *j = *k;
        *k = temp;
      }
    }
    ++j;
  }
}

void printArray(int *arr, int len) {
  int *end = arr + len;
  while (arr < end)
    printf("%i\n", *arr++);
}
