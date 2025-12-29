/* This program transposes a matrix */
#include <stdio.h>

void transpose_matrix(int n_rows, int n_cols, int m1[n_rows][n_cols],
                      int m2[n_cols][n_rows]) {
  for (int j = 0; j < n_rows; ++j)
    for (int k = 0; k < n_cols; ++k)
      m2[k][j] = m1[j][k];
}

int main(void) {
  int n_rows = 4, n_cols = 5;
  int m1[n_rows][n_cols] = {};
  int m2[n_cols][n_rows] = {};

  for (int j = 0; j < n_rows; ++j)
    for (int k = 0; k < n_cols; ++k)
      m1[j][k] = j + k + 1;

  printf("Array 1:\n");
  for (int j = 0; j < n_rows; ++j) {
    for (int k = 0; k < n_cols; ++k)
      printf("%4i", m1[j][k]);

    printf("\n");
  }

  transpose_matrix(n_rows, n_cols, m1, m2);

  printf("Array 2:\n");
  for (int j = 0; j < n_cols; ++j) {
    for (int k = 0; k < n_rows; ++k)
      printf("%4i", m2[j][k]);

    printf("\n");
  }

  return 0;
}
