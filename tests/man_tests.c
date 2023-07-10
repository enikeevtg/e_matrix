#include <stdio.h>

#include "../e_matrix.h"

int main(int argc, char** argv) {
  int rows = 3;
  int columns = 3;
  matrix_t res = {0};
  int create_error = simple_filling(rows, columns, &res, 1);
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
  int A_columns = 3;
  matrix_t A = {0};
  simple_filling(A_rows, A_columns, &A, 1);
  printf("matrix A =\n");
  print_matrix(&A);

  int B_rows = 3;
  int B_columns = 3;
  matrix_t B = {0};
  simple_filling(B_rows, B_columns, &B, 1);
  printf("matrix B =\n");
  print_matrix(&B);

  printf("equal code: %d\n\n", e_eq_matrix(&A, &B));

  // summation
  matrix_t C;
  printf("matrix (A + B) =\n");
  if (!e_sum_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // subtraction
  printf("matrix (A - B) =\n");
  if (!e_sub_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // multiplication by scalar
  double scalar = -1.;
  printf("matrix scalar x A =\n");
  if (!e_mult_number(&A, scalar, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // matrices multiplication
  printf("A x B =\n");
  if (!e_mult_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }

  // transpose
  print_matrix(&A);
  printf("A^T =\n");
  if (!e_transpose(&A, &res)) {
    print_matrix(&res);
  } else {
    printf("error\n");
  }

  return 0;
}
