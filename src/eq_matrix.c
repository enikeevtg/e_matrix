/**
 * @brief matrices comparison
 * @param A is matrix pointer
 * @param B is matrix pointer
 * @return error code
 */

#include "../e_matrix.h"

int e_eq_matrix(matrix_t* A, matrix_t* B) {
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
