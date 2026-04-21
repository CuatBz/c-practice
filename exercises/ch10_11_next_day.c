// This program determines tomorrow's date passing a struct by pointer
#include <stdbool.h>
#include <stdio.h>

struct date {
  int day;
  int month;
  int year;
};

// Function to calculate tomorrow's date
void dateUpdate(struct date today, struct date *tomorrow) {
  int numberOfDays(struct date d);

  if (today.day != numberOfDays(today)) {
    tomorrow->day = today.day + 1;
    tomorrow->month = today.month;
    tomorrow->year = today.year;
  } else if (today.month == 12) { // end of year
    tomorrow->day = 1;
    tomorrow->month = 1;
    tomorrow->year = today.year + 1;
  } else { // end of month
    tomorrow->day = 1;
    tomorrow->month = today.month + 1;
    tomorrow->year = today.year;
  }
}

// Function to find the number of days in a month
int numberOfDays(struct date d) {
  int days;
  bool isLeapYear(struct date d);
  const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (isLeapYear(d) && d.month == 2)
    days = 29;
  else
    days = daysPerMonth[d.month - 1];

  return days;
}

// Function to determine if it's a leap year
bool isLeapYear(struct date d) {
  bool leapYearFlag;

  if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
    leapYearFlag = true; // It's a leap year
  else
    leapYearFlag = false; // Not a leap year

  return leapYearFlag;
}

int main(void) {
  void dateUpdate(struct date today, struct date * tomorrow);
  struct date thisDay, nextDay;

  printf("Enter today's date (dd mm yyyy): ");
  scanf("%i%i%i", &thisDay.day, &thisDay.month, &thisDay.year);

  dateUpdate(thisDay, &nextDay);

  printf("Tomorrow's date is %02i / %02i / %02i.\n ", nextDay.day,
         nextDay.month, nextDay.year % 100);

  return 0;
}
