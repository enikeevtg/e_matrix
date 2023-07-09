#include <stdio.h>

#include "e_matrix.h"

int main(int argc, char** argv) {
  int rows = 1;
  int columns = 1;
  matrix_t res = {0};
  int create_error = e_create_matrix(rows, columns, &res);
  printf("\nerror code: %d\n", create_error);

  // filling
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      res.matrix[i][j] = 10 * (i + 1) + j + 1;
      // printf("%d-%d %.0lf\n", i, j, res.matrix[i][j]);
    }

  // printing #1
  printf("\nprinting #1\n");
  for (int i = 0; i < rows * columns; i++) printf(" %.0lf", *(*res.matrix + i));
  printf("\n");

  // printing #2
  printf("\nprinting #2\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      printf(" %.0lf", *(*(res.matrix + i) + j));
    printf("\n");
  }

  // printing #3
  printf("\nprinting #3\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) printf(" %.0lf", res.matrix[i][j]);
    printf("\n");
  }

  // matrix removing
  free(res.matrix);
  res.matrix = NULL;
  int error = e_remove_matrix(&res);
  printf("\nerror code: %d\n", error);
  return 0;
}
