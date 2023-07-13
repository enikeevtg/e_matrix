/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

int det_calc(matrix_t* A, double* result);
int det_calc_v1(matrix_t* A, int size, double* result);

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
    matrix_t minor = {0};
    double minor_det = 0;
    for (int i = 0; !error && i < size; i++) {
      error = create_minor(&minor, A, i);
      if (!error) error = det_calc(&minor, &minor_det);
      if (!error && !((i + 1) % 2)) minor_det *= -1;
      if (!error) *result += A->matrix[0][i] * minor_det;
    }
    // MEMORY FREEING
    e_remove_matrix(&minor);
  }
  return error;
}

/// @brief matrix determinant calculation
/// made as multiplication first row of the matrix
/// with according algebraic complementations vector:
/// [a1j] x [M.j]^T
/// @version v.1
/// @param A matrix 1x1 or greater
/// @param size matrix size
/// @param result determinant value
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int det_calc_v1(matrix_t* A, int size, double* result) {
  int error = OK;
  *result = **(A->matrix);
  if (A->rows > 1) {
    // FIRST_ROW LINE MATRIX CREATING
    matrix_t first_row = {0};
    error = e_create_matrix(1, size, &first_row);
    if (!error)
      for (int i = 0; i < size; i++) first_row.matrix[0][i] = A->matrix[0][i];

    // COMPLEMENTS_VECTOR CALCULATION
    matrix_t minor = {0};
    matrix_t complements_vector = {0};
    error = e_create_matrix(size, 1, &complements_vector);
    for (int i = 0; !error && i < size; i++) {
      error = create_minor(&minor, A, i);
      if (!error)
        error = det_calc_v1(&minor, size - 1, complements_vector.matrix[i]);
      if (!error && !((i + 1) % 2)) complements_vector.matrix[i][0] *= -1;
    }

    // DETERMINANT CALCULATION
    matrix_t tmp_result = {0};
    if (!error)
      error = e_mult_matrix(&first_row, &complements_vector, &tmp_result);
    if (!error) *result = **tmp_result.matrix;

    // MEMORY FREEING
    e_remove_matrix(&first_row);
    e_remove_matrix(&complements_vector);
    e_remove_matrix(&minor);
    e_remove_matrix(&tmp_result);
  }
  return error;
}
