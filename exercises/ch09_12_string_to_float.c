// This program convers a string to an integer, including negatives
#include <stdbool.h>
#include <stdio.h>

float strToFloat(const char string[]) {
  int i;
  float floatValue = 0.0, result = 0.0, fractional = 0.0;
  bool isNegative = false;

  if (string[0] == '-') {
    isNegative = true;
    i = 1;
  } else {
    i = 0;
  }
  for (; string[i] >= '0' && string[i] <= '9'; ++i) {
    floatValue = string[i] - '0';
    result = result * 10 + floatValue;
  }

  if (string[i++] == '.') {
    float place_val = 1;
    for (; string[i] >= '0' && string[i] <= '9'; ++i) {
      place_val *= 10;
      floatValue = string[i] - '0';
      fractional = fractional + (floatValue / (place_val));
    }
  }

  result += fractional;

  if (isNegative)
    result *= -1;

  return result;
}

int main(void) {
  float strToFloat(const char string[]);

  printf("%f\n", strToFloat("-457.245"));
  printf("%f\n", strToFloat("100") + 25);
  printf("%f\n", strToFloat("13x5"));

  return 0;
}
