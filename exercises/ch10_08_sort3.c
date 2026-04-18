// This function sorts 3 numbers without using arrays
#include <stdio.h>

void sort3(int *n1, int *n2, int *n3);

int main(void) {
  int n1 = 7, n2 = 3, n3 = 4;

  printf("n1: %i, n2: %i, n3:P %i\n", n1, n2, n3);

  sort3(&n1, &n2, &n3);
  printf("n1: %i, n2: %i, n3:P %i\n", n1, n2, n3);

  return 0;
}

void sort3(int *n1, int *n2, int *n3) {
  int temp;

  if (*n1 > *n3) {
    temp = *n1;
    *n1 = *n3;
    *n3 = temp;
  }
  if (*n1 > *n2) {
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
  }

  if (*n2 > *n3) {
    temp = *n2;
    *n2 = *n3;
    *n3 = temp;
  }
}
