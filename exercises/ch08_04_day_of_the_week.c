/* This program tells you the day of the week given a date */
#include <stdio.h>

struct date {
  int day;
  int month;
  int year;
};

int day_num(int N);

int days_passed(struct date d);

int main(void) {
  int day_val;
  struct date input_date;
  char week_days[][10] = {{'S', 'u', 'n', 'd', 'a', 'y', '\0'},
                          {'M', 'o', 'n', 'd', 'a', 'y', '\0'},
                          {'T', 'u', 'e', 's', 'd', 'a', 'y', '\0'},
                          {'W', 'e', 'd', 'n', 'e', 's', 'd', 'a', 'y', '\0'},
                          {'T', 'h', 'u', 'r', 's', 'd', 'a', 'y', '\0'},
                          {'F', 'r', 'i', 'd', 'a', 'y', '\0'},
                          {'S', 'a', 't', 'u', 'r', 'd', 'a', 'y', '\0'}};

  printf("Let's find out what day of the week given a date!\n");
  printf("Please enter a date (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &input_date.day, &input_date.month, &input_date.year);

  day_val = day_num(days_passed(input_date));

  printf("The date %.2i/%.2i/%.4i falls on a %s\n", input_date.day,
         input_date.month, input_date.year, week_days[day_val]);

  return 0;
}

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

int day_num(int N) {
  int day_val;

  day_val = N - 621049;
  day_val %= 7;
}
