/* This program counts the rating for a show from 1 - 10 */
#include <stdio.h>

int main(void) {
  int i, response, pos_ans = 10, res_amt;
  int ratingsCounters[pos_ans];

  // Initialize array to zeroes
  for (i = 0; i < pos_ans; ++i)
    ratingsCounters[i] = 0;

  // Ask users how many values should be entered
  printf("How many values would you like to enter: ");
  scanf("%i", &res_amt);

  printf("Enter your responses:\n");

  for (i = 0; i < res_amt;) {
    scanf("%i", &response);

    if (response == 999) {
      break;
    } else if (response < 1 || response > pos_ans) {
      printf("Bad reponse: %i\n", response);
    } else {
      ++ratingsCounters[response - 1];
      ++i;
    }
  }

  printf("\n\nRating     Number of Responses\n");
  printf("----------------------------------\n");

  for (i = 0; i < pos_ans; ++i)
    printf("%4i%14i\n", i + 1, ratingsCounters[i]);

  return 0;
}
