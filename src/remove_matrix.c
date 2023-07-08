#include "../e_matrix.h"

int e_remove_matrix(matrix_t* A) {
  if (!(A->matrix)) return INCORRECT_MATRIX;
  free(A->matrix);
  return OK;
}
