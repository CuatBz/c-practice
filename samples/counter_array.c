/* This program counts the rating for a show from 1 - 10 */
#include <stdio.h>

int main(void) {
  int ratingCounters[11], i, response;

  // Initialize array to zeroes
  for (i = 1; i <= 10; ++i)
    ratingCounters[i] = 0;

  printf("Enter your responses:\n");

  for (i = 1; i <= 20;) {
    scanf("%i", &response);

    if (response < 1 || response > 10)
      printf("Bad reponse: %i\n", response);
    else {
      ++ratingCounters[response];
      ++i;
    }
  }

  printf("\n\nRating     Number of Responses\n");
  printf("----------------------------------\n");

  for (i = 1; i <= 10; ++i)
    printf("%4i%14i\n", i, ratingCounters[i]);

  return 0;
}
