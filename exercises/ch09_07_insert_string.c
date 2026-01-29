/* This program inserts a string into a given point in another string */
#include <my_strings.h>
#include <stdbool.h>
#include <stdio.h>

#define D_LEN 161
#define I_LEN 81

int insertString(const char source[], const char text[], char dest[], int pos);

int main(void) {
  char dest[D_LEN], input[I_LEN], source[I_LEN];
  int pos, result;

  printf("Please enter some text: ");
  nl_readLine(source, I_LEN);

  printf("\nText:\n%s\n", source);

  printf("Please enter text to insert in previous text: ");
  nl_readLine(input, I_LEN);

  printf("Please enter the position where to insert text: ");
  scanf("%i", &pos);

  result = insertString(source, input, dest, pos);

  if (result == 1)
    printf("\nOperation failed\n");
  else
    printf("\n%s\n", dest);

  return 0;
}

int insertString(const char source[], const char text[], char dest[], int pos) {
  char temp[I_LEN];
  int index = 0, count;

  // Check to see we start at a valid position
  for (int i = 0; i < pos; ++i) {
    if (source[i] == '\0' || source[i] == EOF) {
      printf("\nInvalid starting position\n");
      return 1;
    }
  }

  // Copy characters after start point to temp
  do {
    temp[index] = source[pos + index - 1];
    ++index;
  } while (source[index - 1] != '\0');

  printf("\ntemp: %s\n", temp);

  // Copy up to starting point to dest
  for (int i = 0; i < pos - 1; ++i) {
    dest[i] = source[i];
  }

  // Inset text at point user specified
  index = 0;
  do {
    dest[pos + index - 1] = text[index];
    ++index;
  } while (text[index] != '\0');

  // Re-insert text from original string
  count = index;
  index = 0;
  do {
    dest[pos + count + index - 1] = temp[index];
    ++index;
  } while ((temp[index] - 1) != '\0');

  return 0;
}
