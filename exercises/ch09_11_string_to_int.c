// This program convers a string to an integer, including negatives
#include <stdbool.h>
#include <stdio.h>

int strToInt(const char string[]) {
  int i, intValue, result = 0;
  bool isNegative;

  if (string[0] == '-') {
    isNegative = true;
    i = 1;
  } else {
    i = 0;
  }
  for (; string[i] >= '0' && string[i] <= '9'; ++i) {
    intValue = string[i] - '0';
    result = result * 10 + intValue;
  }

  if (isNegative)
    result *= -1;

  return result;
}

int main(void) {
  int strToInt(const char string[]);

  printf("%i\n", strToInt("-245"));
  printf("%i\n", strToInt("100") + 25);
  printf("%i\n", strToInt("13x5"));

  return 0;
}
