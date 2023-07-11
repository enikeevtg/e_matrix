/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix removing (memory freeing) function
/// @param A matrix pointer
/// @return error code: OK 0, INCORRECT_MATRIX 1
int e_remove_matrix(matrix_t* A) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  free(A->matrix);
  return OK;
}
