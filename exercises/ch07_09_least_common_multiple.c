/* This program calculates the least common multiple of two values */
#include <stdio.h>

int gcd(int u, int v) {
  int temp;

  while (v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  return u;
}

int lcm(int u, int v) { return (u * v / gcd(u, v)); }

int main(void) {
  int u, v, result;

  printf("Enter two numbers for lCM\n");
  scanf("%i", &u);
  scanf("%i", &v);

  result = lcm(u, v);
  printf("\nThe LCM of %i and %i is %i\n", u, v, result);

  return 0;
}
