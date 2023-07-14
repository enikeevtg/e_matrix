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
      e_remove_matrix(&minor_matrix);
    }
  }
  return OK;
}
