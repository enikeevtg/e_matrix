/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix
/// @param A is matrix pointer
/// @param result is result matrix pointer
/// @return error code
/// @warning A and result must be in different memory parts allocated
int e_transpose(matrix_t* A, matrix_t* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (e_create_matrix(A->columns, A->rows, result)) return CALCULATION_ERROR;

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}