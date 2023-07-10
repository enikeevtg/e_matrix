#include "../e_matrix.h"

/// @brief inverse of the matrix
/// @param A matrix pointer
/// @param result result matrix pointer
/// @return error code
int e_inverse_matrix(matrix_t* A, matrix_t* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  double det = 0.f;
  int error = e_determinant(A, &det);
  if (!error && det) {  // det != 0, so matrix has an inverse
    matrix_t complemets = {0};
    error = e_create_matrix(A->rows, A->columns, &complemets);
    matrix_t transpose = {0};
    error = e_create_matrix(A->rows, A->columns, &transpose);
    if (!error) error = e_calc_complements(A, &complemets);
    if (!error) error = e_transpose(&complemets, &transpose);
    if (!error) error = e_mult_number(&transpose, 1 / det, result);
    e_remove_matrix(&complemets);
    e_remove_matrix(&transpose);
  }
  return error;
}
