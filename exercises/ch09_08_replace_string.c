/* This program replaces text inside another string with other text */
#include <my_strings.h>
#include <stdbool.h>
#include <stdio.h>

// Macros
#define D_LEN 161
#define I_LEN 81

// Functions
int findString(char source[], const char text[]);
int removeString(char source[], int start, int amount);
int insertString(const char source[], const char text[], char dest[], int pos);
int _stringLength(const char source[]);

void printChars(const char source[]) {
  int index = 0;

  do {
    printf("%i : %c : %i\n", index, source[index], source[index]);
    ++index;
  } while (source[index - 1] != '\0');
}

int main(void) {
  char source[D_LEN], s1[I_LEN], s2[I_LEN], dest[D_LEN];
  int result, text_len, pos;

  printf("Please enter some text: ");
  nl_readLine(source, I_LEN);

  printf("Text to be replaced: ");
  nl_readLine(s1, I_LEN);
  text_len = _stringLength(s1); // get text len for function

  printf("Text to insert: ");
  nl_readLine(s2, I_LEN);

  result = findString(source, s1);

  if (result == -1) {
    printf("\nText not found. Exiting.\n");
    return 1;
  }
  pos = result;

  result = removeString(source, result + 1, text_len);

  if (result == -1) {
    printf("Error finding text\n");
  } else {
    result = insertString(source, s2, dest, pos + 1);
  }

  printf("\nText is:\n%s\n", dest);

  return 0;
}

int findString(char source[], const char text[]) {
  bool in_text = false;
  int j = 0, k;

  while (source[j] != '\0') {
    k = 0;
    while (text[k] != '\0') {
      if (source[j + k] == text[k]) {
        in_text = true;
        ++k;
      } else {
        in_text = false;
        break;
      }
    }

    // Check if text was found
    if (in_text == true)
      return j;

    ++j;
  }

  return -1;
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
  } while (source[pos + index - 2] != '\0');

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
  } while ((temp[index - 1]) != '\0');

  return 0;
}

// Helper functions

int _stringLength(const char source[]) {
  int count = 0;

  while (source[count] != '\0')
    ++count;

  return count;
}
