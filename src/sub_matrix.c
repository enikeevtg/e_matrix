/**
 * @brief matrices subtracting
 * @param A is matrix pointer
 * @param B is matrix pointer
 * @param result is result matrix pointer
 * @return error code
 */

#include "../e_matrix.h"

int e_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return sum_or_sub(A, B, result, SUBTRACTION);
}

int e_sub_matrix_v1(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int i = A->rows * A->columns;
  while (i--) result->matrix[0][i] = A->matrix[0][i] - B->matrix[0][i];
  return OK;
}
