// This program returns the size of an int in a given machine
#include <stdio.h>

int int_size(int n);

int main(void) {
  int n = ~0;

  printf("This machine uses %i bits for an int\n", int_size(n));

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
