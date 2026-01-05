/* This program calculates how many days have passed between two given dates */
#include <stdio.h>

struct date {
  int day;
  int month;
  int year;
};

// Function declarations
int days_passed(struct date d);
int days_difference(int a, int b);
int absolute(int x);

int main(void) {
  struct date dates[2];
  int elapsed_days[2];
  int difference;

  printf("Please enter the first date (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &dates[0].day, &dates[0].month, &dates[0].year);

  printf("Please enter the second date (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &dates[1].day, &dates[1].month, &dates[1].year);

  elapsed_days[0] = days_passed(dates[0]);
  elapsed_days[1] = days_passed(dates[1]);

  difference = absolute(elapsed_days[0] - elapsed_days[1]);

  printf("There are %i days between %.2i/%.2i/%.4i and %.2i/%.2i/%.4i\n",
         difference, dates[0].day, dates[0].month, dates[0].year, dates[1].day,
         dates[1].month, dates[1].year);

  return 0;
}

// Functions

int days_passed(struct date d) {
  int result, year, month;

  if (d.month <= 2)
    year = d.year - 1;
  else
    year = d.year;

  if (d.month <= 2)
    month = d.month + 13;
  else
    month = d.month + 1;

  result = (1461 * year / 4) + (153 * month / 5) + d.day;

  return result;
}

int days_difference(int a, int b) { return a - b; }

int absolute(int x) {
  if (x < 0)
    return x * -1;
  else
    return x;
}
