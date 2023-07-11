#include <stdio.h>

#include "../e_matrix.h"

int main(int argc, char** argv) {
  int rows = 3;
  int columns = 3;
  matrix_t res = {0};
  int create_error = simple_filling(rows, columns, &res, 1);
  printf("\n\033[33mcreate_matrix error code:\033[0m %d\n", create_error);

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
  printf("\n\033[33mremoving error code:\033[0m %d\n\n", error);

  // matrix comparison
  int A_rows = 3;
  int A_columns = 3;
  matrix_t A = {0};
  simple_filling(A_rows, A_columns, &A, 0);
  printf("matrix A =\n");
  print_matrix(&A);

  int B_rows = 3;
  int B_columns = 3;
  matrix_t B = {0};
  simple_filling(B_rows, B_columns, &B, 1);
  printf("matrix B =\n");
  print_matrix(&B);

  printf("\033[33mequal code:\033[0m %d\n\n", e_eq_matrix(&A, &B));

  // summation
  matrix_t C;
  printf("\033[33mmatrix (A + B) =\033[0m\n");
  if (!e_sum_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // subtraction
  printf("\033[33mmatrix (A - B) =\033[0m\n");
  if (!e_sub_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // multiplication by scalar
  double scalar = -1.f;
  printf("\033[33mmatrix scalar x A =\033[0m\n");
  if (!e_mult_number(&A, scalar, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }
  e_remove_matrix(&C);

  // matrices multiplication
  printf("A x B =\033[0m\n");
  if (!e_mult_matrix(&A, &B, &C)) {
    print_matrix(&C);
  } else {
    printf("error\n");
  }

  // transpose
  printf("\n\033[33mtranspose test\033[0m\nA =");
  print_matrix(&A);
  printf("A^T =\n");
  if (!e_transpose(&A, &res)) {
    print_matrix(&res);
  } else {
    printf("error\n");
  }

  // calc_complements
  printf("\n\033[33mcalc_complements test\033[0m");
  A.matrix[0][0] = 1.f;
  A.matrix[0][1] = 2.f;
  A.matrix[0][2] = 3.f;
  A.matrix[0][3] = 0.f;
  A.matrix[0][4] = 4.f;
  A.matrix[0][5] = 2.f;
  A.matrix[0][6] = 5.f;
  A.matrix[0][7] = 2.f;
  A.matrix[0][8] = 1.f;
  printf("\ntest #1\nA =\n");
  print_matrix(&A);
  printf("M. =\n");
  e_calc_complements(&A, &res);
  print_matrix(&res);
  e_remove_matrix(&res);

  A.matrix[0][0] = 2.f;
  A.matrix[0][1] = 5.f;
  A.matrix[0][2] = 7.f;
  A.matrix[0][3] = 6.f;
  A.matrix[0][4] = 3.f;
  A.matrix[0][5] = 4.f;
  A.matrix[0][6] = 5.f;
  A.matrix[0][7] = -2.f;
  A.matrix[0][8] = -3.f;
  // calc_complements
  printf("\ntest #2\nA =\n");
  print_matrix(&A);
  printf("M. =\n");
  e_calc_complements(&A, &res);
  print_matrix(&res);
  e_remove_matrix(&res);

  // determinant
  printf("\033[33mdeterminant test\033[0m\nA =\n");
  print_matrix(&A);
  double det = 0;
  e_determinant(&A, &det);
  printf("determinant = %lf\n", det);

  // inverse
  printf("\033[33minverse test\033[0m\nA =\n");
  print_matrix(&A);
  e_inverse_matrix(&A, &res);
  printf("inverse =\n");
  print_matrix(&res);

  return 0;
}
