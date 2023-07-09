/**
 * @brief matrix removing (memory freeing) function
 * @param rows
 * @param columns
 * @param result
 * @return error code
 */

#include "../e_matrix.h"

int e_remove_matrix(matrix_t* A) {
  if (A->matrix == NULL) return INCORRECT_MATRIX;
  free(A->matrix);
  return OK;
}
