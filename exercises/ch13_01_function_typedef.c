// This program uses typedef for a pointer to a function
#include <stdio.h>

int printText(void);

typedef int (*intFnVoidPtr)(void);

int main(void) {
  intFnVoidPtr printFn;
  printFn = printText;
  int result;

  printf("Here is our function:\n");

  result = printFn();

  printf("\nThe result is %i\n", result);

  return 0;
}

int printText(void) {
  char buf[81];

  printf("Please enter some text:\n");

  scanf("%s", buf);

  printf("The text is:\n%s", buf);

  return 0;
}
