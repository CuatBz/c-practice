#include <my_strings.h>
#include <stdio.h>

int main(void) {
  char buf[81];
  int c, count;

  printf("Please enter some text: ");
  readLine(buf, 81);

  count = 0;
  do {
    c = buf[count];
    printf("\n%i", c);
    ++count;
  } while (buf[count] != '\0');

  printf("\n%i\n", c);

  return 0;
}
