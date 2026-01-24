/* This program extracts a portion from a string */
#include <my_strings.h>
#include <stdio.h>

#define LEN 81

int substring(const char source[], int len, int start, int count,
              char result[]);

int main(void) {
  char input[LEN], result[LEN];
  int start, count, is_valid;

  printf("Please enter some text: ");
  readLine(input, LEN);

  printf("Please enter the position from where you want to start copying:\n");
  scanf("%i", &start);

  printf("Enter how many characters you want to copy from start point:\n");
  scanf("%i", &count);

  is_valid = substring(input, LEN, start - 1, count, result);

  if (is_valid == 0)
    printf("\nThe substring is:\n%s\n", result);

  return is_valid;
}

int substring(const char source[], int len, int start, int count,
              char result[]) {
  if ((start + count) < len && start > 0) {
    int i;

    for (i = 0; i < count; ++i)
      result[i] = source[start + i];

    result[i] = '\0';
    return 0;
  } else {
    printf("\nInvalid parameters\n");
    return -1;
  }
}
