/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrices comparison
/// @param A is matrix pointer
/// @param B is matrix pointer
/// @return error code
int e_eq_matrix(matrix_t* A, matrix_t* B) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;

  int equal = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    equal = FAILURE;
  } else {
    int i = A->rows * A->columns;
    while (i-- && equal)
      if (A->matrix[0][i] != B->matrix[0][i]) equal = FAILURE;
  }
  return equal;
}
