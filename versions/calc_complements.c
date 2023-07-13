/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief algebraic complements matrix calculation
/// by using determinant calculation function
/// @version v.2
/// @param A matrix pointer
/// @param result result matrix pointer
/// @return error code
int e_calc_complements(matrix_t* A, matrix_t* result) {
  if (result) matrix_init(result);
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  **result->matrix = **A->matrix;
  if (A->rows > 1) {
    int error = OK;
    int i = A->rows * A->columns;
    matrix_t minor_matrix = {0};
    while (error == OK && i--) {
      error = create_minor(&minor_matrix, A, i);
      error = e_determinant(&minor_matrix, &result->matrix[0][i]);
      if (!error && ((i / A->columns + i % A->columns) % 2))
        result->matrix[0][i] *= -1;
    }
  }
  return 0;
}

/// @brief algebraic complements matrix calculation
/// @warning working for 3x3 matrix only
/// @version v.1
/// @param A matrix pointer
/// @param result result matrix pointer
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_calc_complements_v1(matrix_t* A, matrix_t* result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int current_elem = A->rows * A->columns;
  int error = OK;
  matrix_t minor_matrix = {0};
  error = e_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
  while (error == OK && current_elem--) {
    error = create_minor(&minor_matrix, A, current_elem);
    result->matrix[0][current_elem] =
        minor_matrix.matrix[0][0] * minor_matrix.matrix[1][1] -
        minor_matrix.matrix[0][1] * minor_matrix.matrix[1][0];
  }
  return 0;
}
