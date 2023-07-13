/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

int det_calc(matrix_t* A, double* result);

/// @brief matrix determinant calculation main function
/// @param A square matrix pointer
/// @param result deteminant of matrix
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_determinant(matrix_t* A, double* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns || result == NULL) return CALCULATION_ERROR;
  return det_calc(A, result);
}

/// @brief matrix determinant calculation
/// @version v.2
/// @param A matrix 1x1 or greater
/// @param size matrix size
/// @param result determinant value
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int det_calc(matrix_t* A, double* result) {
  int error = OK;
  int size = A->rows;
  *result = **(A->matrix);
  if (size > 1) {
    *result = 0.f;
    matrix_t minor_matrix = {0};
    double minor_det = 0;
    for (int i = 0; !error && i < size; i++) {
      error = create_minor(&minor_matrix, A, i);
      if (!error) error = det_calc(&minor_matrix, &minor_det);
      if (!error && !((i + 1) % 2)) minor_det *= -1;
      if (!error) *result += A->matrix[0][i] * minor_det;
      e_remove_matrix(&minor_matrix);
    }
    // MEMORY FREEING
  }
  return error;
}
