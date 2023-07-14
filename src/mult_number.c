/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix multiplication by scalar
/// @param A matrix pointer
/// @param number scalar
/// @param result result matrix pointer
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_mult_number(matrix_t* A, double number, matrix_t* result) {
  if (result) matrix_init(result);
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int i = A->rows * A->columns;
  while (i--) result->matrix[0][i] = number * A->matrix[0][i];
  return OK;
}
