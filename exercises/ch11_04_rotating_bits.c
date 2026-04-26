// Program to illustrate rotation of integers
#include <stdio.h>

int int_size(int n);

int main(void) {
  unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;
  unsigned int rotate(unsigned int value, int n, int i_size);

  int n = int_size(~0);

  printf("%x\n", rotate(w1, 8, n));
  printf("%x\n", rotate(w1, -16, n));
  printf("%x\n", rotate(w2, 4, n));
  printf("%x\n", rotate(w2, -2, n));
  printf("%x\n", rotate(w1, 0, n));
  printf("%x\n", rotate(w1, 44, n));

  return 0;
}

int int_size(int n) {
  int i = 0;

  while (n) {
    n <<= 1;
    i++;
  };

  return i;
}

// Function to rotate an unsigned int left or right
unsigned int rotate(unsigned int value, int n, int i_size) {
  unsigned int result, bits;

  // scale down the shift count to a defined range
  if (n > 0)
    n = n % i_size;
  else
    n = -(-n % i_size);

  if (n == 0)
    result = value;
  else if (n > 0) { // left rotate
    bits = value >> (i_size - n);
    result = value << n | bits;
  } else { // right rotate
    n = -n;
    bits = value << (i_size - n);
    result = value >> n | bits;
  }

  return result;
}
