/**
 * @brief matrix removing (memory freeing) function
 * @param A is matrix pointer
 * @return error code
 */

#include "../e_matrix.h"

int e_remove_matrix(matrix_t* A) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  free(A->matrix);
  return OK;
}
