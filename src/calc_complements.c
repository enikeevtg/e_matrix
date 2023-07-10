#include "../e_matrix.h"

/// @version v.2
int e_calc_complements(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int current_elem = A->rows * A->columns;
  int error_code = OK;
  matrix_t minor = {0};
  error_code = e_create_matrix(A->rows - 1, A->columns - 1, &minor);
  while (error_code == OK && current_elem--) {
    minor_filling(&minor, A, current_elem);
    result->matrix[0][current_elem] = minor.matrix[0][0] * minor.matrix[1][1] -
                                      minor.matrix[0][1] * minor.matrix[1][0];
  }
  return 0;
}

/// @version v.1
int e_calc_complements_v1(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int current_elem = A->rows * A->columns;
  int error_code = OK;
  matrix_t minor = {0};
  error_code = e_create_matrix(A->rows - 1, A->columns - 1, &minor);
  while (error_code == OK && current_elem--) {
    minor_filling(&minor, A, current_elem);
    result->matrix[0][current_elem] = minor.matrix[0][0] * minor.matrix[1][1] -
                                      minor.matrix[0][1] * minor.matrix[1][0];
  }
  return 0;
}
