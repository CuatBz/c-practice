// This program helps to determine if the computer performs a logical
// or arithmetic right shift
#include <stdio.h>

void showBits(int n);

int main(void) {
  int n1 = -17, n2 = 25;

  printf("-17:\n");
  showBits(n1);

  printf("\n25:\n");
  showBits(n2);

  n1 >>= 3;
  printf("\n-17 right shifted by 3\n");
  showBits(n1);

  n2 >>= 2;
  printf("\n25 right shifted by 2\n");
  showBits(n2);
  return 0;
}

void showBits(int n) {
  int i;
  int j, k, mask;

  for (i = 31; i >= 0; i--) {
    j = i;
    mask = 1 << j;
    k = n & mask;
    k == 0 ? printf("0") : printf("1");

    if (i != 31 && (i % 4 == 0))
      printf(" ");
  }
}
