// This program sets a certain amount of bits from a pattern in another number
#include <stdio.h>

#define I_LEN 32

void bit_pat_set(unsigned int *n, unsigned int p, int start, int range);
void showBits(unsigned int n);
void showRange(int start, int range);

int main(void) {
  unsigned int n = 43785893, p = 73;
  int start = 11, range = 5;

  printf("Number is %u\n", n);
  showBits(n);

  printf("\nPattern is %u\n", p);
  showBits(p);

  printf("\nThe range is:\n");
  showRange(start, range);

  bit_pat_set(&n, p, start, range);

  printf("\nNumber is now: %u\n", n);
  showBits(n);

  return 0;
}

void bit_pat_set(unsigned int *n, unsigned int p, int start, int range) {
  unsigned int mask = 0, temp = 0;

  // Take only the range of bits from the pattern
  if (range <= 0) {
    return;
  } else {
    mask = ~0u;
    mask >>= (I_LEN - range);
    p &= mask;
  }

  // Zero out range in the number
  mask = ~0u;

  for (int i = (I_LEN - start - 1); i >= (I_LEN - start - range); i--) {
    mask ^= (1 << i);
  }
  *n &= mask;

  // Copy bits into zeroed out space
  *n |= (p << (I_LEN - start - range));
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

  // Left shift mask all the way to start point
  mask <<= (I_LEN - start - 1);
  // printf("\nMask start:\n");
  // showBits(mask);

  for (int i = 0; i < range; i++) {
    temp |= mask;
    mask >>= 1;
  }

  printf("\nRange highlighter:\n");
  showBits(temp);
}
