/* This program removes a section of a string */
#include <my_strings.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 81

int removeString(char source[], int start, int amount);

int main(void) {
  char buf[LEN];
  int start, amount, result;

  printf("Please enter some text: ");
  nl_readLine(buf, LEN);

  printf("\nLet's remove some text. Enter the starting point: ");
  scanf("%i", &start);

  printf("\nCharacters to remove: ");
  scanf("%i", &amount);

  result = removeString(buf, start, amount);

  if (result == 0) {
    printf("The strings is now:\n%s\n", buf);
  } else {
    printf("\nError. Please try again.\n");
  }

  return 0;
}

int removeString(char source[], int start, int amount) {
  int c, i, end = start + amount - 2;
  bool ends_empty = false;

  // Checking to make sure we don't start after string end
  for (i = 0; i < start; ++i) {
    c = source[i];

    if (c == '\0' || c == EOF) {
      printf("\nInvalid starting point\n");
      return -1;
    }
  }

  // Checking to see if characters to be deleted are at string's end
  for (int j = start - 1; j <= end; ++j) {
    c = source[j];

    if (c == '\0' || c == EOF) {
      ends_empty = true;
      break;
    }
  }

  if (ends_empty) {
    source[start - 1] = '\0';
    return 0;
  } else {
    int index = 0;
    do {
      source[start - 1 + index] = source[end + index + 1];
      ++index;
    } while (source[end + index] != '\0');
    return 0;
  }
}
