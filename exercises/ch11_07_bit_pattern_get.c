// This program gets bits for a range in a number
#include <stdio.h>

#define I_LEN 32

unsigned int bit_pat_get(unsigned int source, int start, int range);
void showBits(unsigned int n);
void showRange(int start, int range);

int main(void) {
  unsigned int source = 54363489, result;
  int start, range;

  printf("Source: %u\n", source);
  showBits(source);

  start = 12;
  range = 12;

  showRange(start, range);

  result = bit_pat_get(source, start, range);

  printf("\nResult: %u\n", result);
  showBits(result);

  return 0;
}

unsigned int bit_pat_get(unsigned int source, int start, int range) {
  unsigned int temp = 0, mask = 1;

  // Left shift mask all the way to the starting point
  mask <<= (I_LEN - start - 1);

  for (int i = 0; i < range; i++) {
    temp |= (mask & source);
    mask >>= 1;
  }

  return temp;
}

void showBits(unsigned int n) {
  int i, j;
  unsigned int mask, k;

  for (i = (I_LEN - 1); i >= 0; i--) {
    j = i;
    mask = 1 << j;
    k = n & mask;
    k == 0 ? printf("0") : printf("1");

    if (i != (I_LEN - 1) && (i % 4 == 0))
      printf(" ");
  }
}

void showRange(int start, int range) {
  unsigned int temp = 0, mask = 1;

  printf("\nTemp start:\n");
  showBits(temp);

  // Left shift mask all the way to start point
  mask <<= (I_LEN - start - 1);
  printf("\nMask start:\n");
  showBits(mask);

  for (int i = 0; i < range; i++) {
    temp |= mask;
    mask >>= 1;
  }

  printf("\nRange highlighter:\n");
  showBits(temp);
}
