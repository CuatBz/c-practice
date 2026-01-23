#include <my_strings.h>
#include <stdio.h>

int main(void) {
  char buf[81];

  printf("Please enter some text: ");
  readLine(buf, 81);

  printf("Your text is:\n%s\n", buf);

  return 0;
}
