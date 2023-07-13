/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrices comparison
/// @param A matrix pointer
/// @param B matrix pointer
/// @return comparison code: SUCCESS - 1, FAILURE - 0
int e_eq_matrix(matrix_t* A, matrix_t* B) {
  if (!valid_matrix(A) || !valid_matrix(B)) return FAILURE;  // ?

  int equal = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    equal = FAILURE;
  } else {
    int i = A->rows * A->columns;
    while (i-- && equal != FAILURE)
      if (fabs(A->matrix[0][i] - B->matrix[0][i]) > PRECISION) equal = FAILURE;
  }
  return equal;
}
