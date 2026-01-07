/* This function allows you to keep track of time using structs*/
#include <stdbool.h>
#include <stdio.h>

// Structs

struct time {
  int hours;
  int minutes;
  int seconds;
};

struct date {
  int day;
  int month;
  int year;
};

struct date_time {
  struct date s_date;
  struct time s_time;
};

// Function declarations
struct date_time timeUpdate(struct date_time d_t);
struct date dateUpdate(struct date today);
int numberOfDays(struct date d);
bool isLeapYear(struct date d);

int main(void) {
  struct date_time d_t;

  printf("Please enter the date (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &d_t.s_date.day, &d_t.s_date.month, &d_t.s_date.year);

  printf("\nPlease enter the time (hh:mm:ss): ");
  scanf("%i:%i:%i", &d_t.s_time.hours, &d_t.s_time.minutes,
        &d_t.s_time.seconds);

  d_t = timeUpdate(d_t);

  printf("The date and time is now %.2i/%.2i/%.2i %.2i:%.2i:%.2i\n",
         d_t.s_date.day, d_t.s_date.month, d_t.s_date.year, d_t.s_time.hours,
         d_t.s_time.minutes, d_t.s_time.seconds);

  return 0;
}

// Function to update time

struct date_time timeUpdate(struct date_time d_t) {
  struct date_time result;
  result = d_t;

  ++result.s_time.seconds;

  if (result.s_time.seconds == 60) {
    result.s_time.seconds = 0;
    ++result.s_time.minutes;

    if (result.s_time.minutes == 60) {
      result.s_time.minutes = 0;
      ++result.s_time.hours;

      if (result.s_time.hours == 24) {
        result.s_time.hours = 0;

        result.s_date = dateUpdate(result.s_date);
      }
    }
  }

  return result;
}

// Functions to calculate tomorrow's date
struct date dateUpdate(struct date today) {
  struct date tomorrow;
  int numberOfDays(struct date d);

  if (today.day != numberOfDays(today)) {
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;
  } else if (today.month == 12) {
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year + 1;
  } else {
    tomorrow.day = 1;
    tomorrow.month = today.month + 1;
    tomorrow.year = today.year;
  }

  return tomorrow;
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
    leapYearFlag = true;
  else
    leapYearFlag = false;

  return leapYearFlag;
}
