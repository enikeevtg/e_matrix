#include "../e_matrix.h"

int e_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int i = A->rows * A->columns;
  while (i--) result->matrix[0][i] = A->matrix[0][i] + B->matrix[0][i];
  return OK;
}
