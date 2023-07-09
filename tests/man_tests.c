#include <stdio.h>

#include "../e_matrix.h"

int main(int argc, char** argv) {
  int rows = 3;
  int columns = 3;
  matrix_t res = {0};
  int create_error = simple_filling(rows, columns, &res);
  printf("\ncreate_matrix error code: %d\n", create_error);

  // printing #1
  printf("\nprinting #1\n");
  print_matrix_inline(&res);

  // printing #2
  printf("\nprinting #2\n");
  print_matrix_v2(&res);

  // printing #3
  printf("\nprinting #3\n");
  print_matrix(&res);

  // matrix removing
  // free(res.matrix);
  // res.matrix = NULL;
  int error = e_remove_matrix(&res);
  printf("\nremoving error code: %d\n\n", error);

  // matrix comparison
  int A_rows = 3;
  int A_columns = 5;
  matrix_t A = {0};
  simple_filling(A_rows, A_columns, &A);
  int B_rows = 3;
  int B_columns = 0;
  matrix_t B = {0};
  simple_filling(B_rows, B_columns, &B);
  printf("matrix A =\n");
  print_matrix(&A);
  printf("matrix B =\n");
  print_matrix(&B);
  printf("equal code: %d\n\n", e_eq_matrix(&A, &B));

  // summation
  matrix_t C;
  e_sum_matrix(&A, &B, &C);
  printf("matrix (A + B) =\n");
  print_matrix(&C);

  // subtraction

  return 0;
}
