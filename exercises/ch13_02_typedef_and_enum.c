// This program makes use of typedef along with enums
#include <stdio.h>

typedef enum {
  January = 1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
} month;

const char *monthName(month m);

typedef const char *(*charFnPtr)(month m);

int main(void) {
  charFnPtr monthFn;
  monthFn = monthName;

  const char *result;

  result = monthFn(April);

  printf("The month is %s\n", result);

  return 0;
}

const char *monthName(month m) {
  switch (m) {
  case January:
    return "January";
    break;
  case February:
    return "February";
    break;
  case March:
    return "March";
    break;
  case April:
    return "April";
    break;
  case May:
    return "May";
    break;
  case June:
    return "June";
    break;
  case July:
    return "July";
    break;
  case August:
    return "August";
    break;
  case September:
    return "September";
    break;
  case October:
    return "October";
    break;
  case November:
    return "November";
    break;
  case December:
    return "December";
    break;
  }
}
