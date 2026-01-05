/* This program calculates how much time has passed between two given times */
#include <stdio.h>

struct time {
  int hours;
  int minutes;
  int seconds;
};

struct time elapsed_time(struct time t1, struct time t2);
int absolute(int x);

int main(void) {
  struct time times[2];
  struct time time_diff;

  printf("Please enter the first time (hh:mm:ss): ");
  scanf("%i:%i:%i", &times[0].hours, &times[0].minutes, &times[0].seconds);

  printf("Please enter the second time (hh:mm:ss): ");
  scanf("%i:%i:%i", &times[1].hours, &times[1].minutes, &times[1].seconds);

  time_diff = elapsed_time(times[0], times[1]);

  printf("The time difference between %i:%.2i:%.2i and %i:%.2i:%.2i"
         " is %i:%.2i:%.2i\n",
         times[0].hours, times[0].minutes, times[0].seconds, times[1].hours,
         times[1].minutes, times[1].seconds, time_diff.hours, time_diff.minutes,
         time_diff.seconds);

  return 0;
}

// Function to calculate elapsed time

struct time elapsed_time(struct time t1, struct time t2) {
  int seconds[2]; // variable that holds the times in seconds
  int sec_diff;
  struct time result;

  seconds[0] = (t1.hours * 60 * 60) + (t1.minutes * 60) + t1.seconds;
  seconds[1] = (t2.hours * 60 * 60) + (t2.minutes * 60) + t2.seconds;

  sec_diff = absolute(seconds[0] - seconds[1]);

  result.seconds = sec_diff % 60;
  sec_diff = sec_diff / 60;

  result.minutes = sec_diff % 60;
  sec_diff = sec_diff / 60;

  result.hours = sec_diff;

  return result;
}

int absolute(int x) {
  if (x < 0)
    return x * -1;
  else
    return x;
}
