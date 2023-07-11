/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief determinant calculation
/// made as multiplication first row of the matrix
/// with according algebraic complementations vector:
/// [a1j] x [M.j]^T
/// @param A square matrix pointer
/// @param result deteminant of matrix
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_determinant(matrix_t* A, double* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  int error = OK;
  int size = A->rows;

  matrix_t first_row = {0};
  error = e_create_matrix(1, size, &first_row);
  if (!error) {
    for (int i = 0; i < size; i++) first_row.matrix[0][i] = A->matrix[0][i];
  }

  matrix_t complements_vector = {0};
  if (!error) error = e_create_matrix(size, 1, &complements_vector);

  if (!error && size == 2) {
    complements_vector.matrix[0][0] = A->matrix[1][1];
    complements_vector.matrix[1][0] = -A->matrix[1][0];
  } else if (!error) {
    matrix_t minor_matrix = {0};
    error = e_create_matrix(size - 1, size - 1, &minor_matrix);
    for (int i = 0; !error && i < size; i++) {
      if (!error) minor_filling(&minor_matrix, A, i);
      error = e_determinant(&minor_matrix, complements_vector.matrix[i]);
      if (!error && !((i + 1) % 2)) complements_vector.matrix[i][0] *= -1;
    }
  }

  matrix_t tmp_result = {0};
  if (!error) error = e_create_matrix(1, 1, &tmp_result);
  if (!error)
    error = e_mult_matrix(&first_row, &complements_vector, &tmp_result);

  if (!error) *result = **tmp_result.matrix;

  e_remove_matrix(&first_row);
  e_remove_matrix(&complements_vector);
  e_remove_matrix(&tmp_result);

  return error;
}
