// This program searches a number for a specific bit pattern
#include <stdio.h>

#define I_LEN 32

int bit_pat_search(unsigned int source, unsigned int pattern, int n);
void showBits(unsigned int n);

int main(void) {
  unsigned int source = 5436342, pattern = 9;
  int amount, result;

  printf("Source:\n");
  showBits(source);

  printf("\nPattern:\n");
  showBits(pattern);

  amount = 4;

  result = bit_pat_search(source, pattern, amount);
  printf("\nThe result is %i\n", result);

  return 0;
}

int bit_pat_search(unsigned int source, unsigned int pattern, int n) {
  unsigned int t_mask = 0, test = 0;

  // Only keep numbers in the range
  for (int i = 0; i < n; i++) {
    t_mask |= (pattern & (1 << i));
  }

  // shift pattern all the way to the left
  t_mask = (t_mask << (I_LEN - n));
  printf("\nt_mask\n");
  showBits(t_mask);

  // Look for pattern in source
  for (int i = 0; i < (I_LEN - n); i++) {
    test = t_mask & source;
    if (test == t_mask) {
      return i;
    } else {
      t_mask >>= 1;
    }
  }

  return -1;
}

void showBits(unsigned int n) {
  int i, j;
  unsigned int mask, k;

  for (i = 31; i >= 0; i--) {
    j = i;
    mask = 1 << j;
    k = n & mask;
    k == 0 ? printf("0") : printf("1");

    if (i != 31 && (i % 4 == 0))
      printf(" ");
  }
}
