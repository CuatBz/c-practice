// This program will merge text from 2 sources
#include <stdio.h>

#define BUF_SIZE 1024
#define F_NAME_LEN 64

int mergeLine(char f1_name[], char f2_name[]);

int main(void) {
  char f1_name[F_NAME_LEN], f2_name[F_NAME_LEN];
  int result;

  printf("Please enter the name of the first file:\n");
  scanf("%63s", f1_name);

  printf("Please enter the name of the second file:\n");
  scanf("%63s", f2_name);

  result = mergeLine(f1_name, f2_name);

  return result;
}

int mergeLine(char f1_name[], char f2_name[]) {
  FILE *file1, *file2;
  char buf1[BUF_SIZE], buf2[BUF_SIZE];
  int c;
  char *res1, *res2;

  if ((file1 = fopen(f1_name, "r")) == NULL) {
    fprintf(stderr, "\nError accessing file: %s\n", f1_name);
    return 1;
  }

  if ((file2 = fopen(f2_name, "r")) == NULL) {
    fprintf(stderr, "\Error accessing file: %s\n", f2_name);
    fclose(file1);
    return 2;
  }

  res1 = fgets(buf1, BUF_SIZE, file1);
  res2 = fgets(buf2, BUF_SIZE, file2);
  while ((res1 != NULL) || (res2 != NULL)) {
    if (res1 != NULL) {
      fputs(buf1, stdout);
      res1 = fgets(buf1, BUF_SIZE, file1);
    }

    if (res2 != NULL) {
      fputs(buf2, stdout);
      res2 = fgets(buf2, BUF_SIZE, file2);
    }
  }

  fclose(file1);
  fclose(file2);

  return 0;
}
