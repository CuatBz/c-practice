// This program will compare strings using pointers
#include <stdio.h>

#define LEN 81

int compareStrings(const char *w1, const char *w2);

int main(void) {
  char w1[LEN] = "hello", w2[LEN] = "there";
  int res;

  res = compareStrings(w1, w1);
  printf("Result for %s and %s is %i\n", w1, w1, res);

  return 0;
}

int compareStrings(const char *w1, const char *w2) {
  while (*w1 && (*w1++ == *w2++))
    ;

  if (*w1 < *w2)
    return -1;
  else if (*w1 == *w2)
    return 0;
  else
    return 1;
}
