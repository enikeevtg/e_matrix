/**
 * @brief matrices adding
 * @param A
 * @param B
 * @param result
 * @return error code
 */

#include "../e_matrix.h"

int e_mult_number(matrix_t* A, double number, matrix_t* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int i = A->rows * A->columns;
  while (i--) result->matrix[0][i] = number * A->matrix[0][i];
  return OK;
}