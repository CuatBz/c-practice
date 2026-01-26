/* This program checks if a string is contained within another */
#include <my_strings.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 81

int findString(const char text[], const char search[]);

int main(void) {
  char input[LEN], search[LEN];
  int result;

  printf("Please enter a string of text: ");
  nl_readLine(input, LEN);

  printf("Please enter some text to search for: ");
  nl_readLine(search, LEN);

  result = findString(input, search);

  if (result == -1)
    printf("\nThat string was not found in the text\n");
  else
    printf("\nThe string was found at position %i\n", result);

  return 0;
}

int findString(const char text[], const char search[]) {
  int anchor = 0, s_point;
  bool is_same;

  while (text[anchor] != '\0') {
    s_point = 0;
    is_same = false;

    while (search[s_point] != '\0') {
      if (text[anchor + s_point] == search[s_point]) {
        is_same = true;
      } else {
        is_same = false;
        ++s_point;
        break;
      }

      ++s_point;
    }

    if (is_same)
      return anchor + 1;

    ++anchor;
  }

  return -1;
}
