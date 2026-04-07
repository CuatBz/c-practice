// This program is a basic demonstration of pointers
#include <stdio.h>

int main(void) {
  int count = 10, x;
  int *int_ptr;

  int_ptr = &count;
  x = *int_ptr;

  printf("count: %d | x: %d\n", count, x);

  return 0;
}
