// This program converts ints to string
#include <stdbool.h>
#include <stdio.h>

void intToStr(int val, char s[]);

int main(void) {
  char val[40];

  intToStr(40, val);
  printf("int: %i | str: %s\n", 40, val);
  intToStr(0, val);
  printf("int: %i | str: %s\n", 0, val);
  intToStr(-27, val);
  printf("int: %i | str: %s\n", -27, val);

  return 0;
}

void intToStr(int val, char s[]) {
  if (val == 0) {
    s[0] = '0';
    s[1] = '\0';

    return;
  }

  int i = 0, d; // index, digit, result
  char temp[50];
  bool isNegative = false;

  if (val < 0) {
    isNegative = true;
    val *= -1;
  }

  while (val > 0) {
    d = val % 10;
    val = val / 10;
    temp[i] = d + '0';
    ++i;
  }

  if (isNegative) {
    s[0] = '-';
    d = 1;
  } else {
    d = 0;
  }

  while (i > 0) {
    --i;
    s[d] = temp[i];
    ++d;
  }
  s[d] = '\0';
}
