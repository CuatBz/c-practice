// This program can check if a bit is set to 1 in a certain number
// and it can turn the bit on at a given location
#include <stdio.h>

unsigned int bit_set(unsigned int n, int p);
int bit_test(unsigned int n, int p);
unsigned int shifted_num(int a);
void showBits(unsigned int n);

int main(void) {
  unsigned int n = 0, ur; // number, unsigned result
  int p, sr;              // position, signed result

  printf("The number is %u\n", n);

  p = 0;
  sr = bit_test(n, p);

  showBits(n);
  printf("\nNum: %u | Bit test: %i\n", n, sr);

  ur = bit_set(n, p);

  printf("\nBit %i was set and the value is now %u\n", p, ur);

  sr = bit_test(ur, p);
  showBits(ur);
  printf("\nNum: %u | Bit test: %i\n", ur, sr);

  return 0;
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

unsigned int bit_set(unsigned int n, int p) {
  unsigned int s = shifted_num(p);

  return s | n;
}

int bit_test(unsigned int n, int p) {
  int s = shifted_num(p);

  if (n & s)
    return 1;
  else
    return 0;
}

unsigned int shifted_num(int a) {
  a = a % 32;

  return 1 << (31 - a);
}
