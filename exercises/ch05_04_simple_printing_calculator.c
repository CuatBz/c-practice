/* This program works as a simple printing calculator */
#include <stdio.h>

int main(void) {
  float accumulator = 0, user_num, result;
  char option;

  printf("Begin Calculations:\n");

  do {
    scanf("%f %c", &user_num, &option);

    switch (option) {
      case 's':
      case 'S':
        accumulator = user_num;
        printf("Set Accumulator to %g\n", accumulator);
        break;

      case 'e':
      case 'E':
        printf("See you soon!\n");
        option = 'E';     // changes it to upper in case it was lower case
        break;

      case 'x':
      case '*':
        accumulator *= user_num;
        printf("= %g\n", accumulator);
        break;

      case '+':
        accumulator += user_num;
        printf("= %g\n", accumulator);
        break;

      case '-':
        accumulator -= user_num;
        printf("= %g\n", accumulator);
        break;

      case '/':
        if (user_num == 0)
          printf("Cannot divide by zero\n");
        else {
          accumulator /= user_num;
          printf("= %g\n", accumulator);
        }
        break;

      default:
        printf("Invalid operator\n");
        break;
    }
  }
  while (option != 'E');

  return 0;
}
