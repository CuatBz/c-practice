/* This program determines if two character arrays are identical */
#include <stdbool.h>
#include <stdio.h>

bool equalStrings(const char s1[], const char s2[]) {
  int i = 0;
  bool areEqual;

  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    ++i;

  if (s1[i] == '\0' && s2[i] == '\0')
    areEqual = true;
  else
    areEqual = false;

  return areEqual;
}

int main(void) {
  bool equalStrings(const char s1[], const char s2[]);
  const char str1[] = "string compare test";
  const char str2[] = "string";

  printf("%i\n", equalStrings(str1, str2));
  printf("%i\n", equalStrings(str1, str1));
  printf("%i\n", equalStrings(str2, "string"));

  return 0;
}
