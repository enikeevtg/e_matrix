#include "../e_matrix.h"

int e_calc_complements(matrix_t *A, matrix_t *result) {
  if (!valid_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int current_elem = A->rows * A->columns;
  matrix_t minor = {0};
  print_matrix(&minor);
  while (current_elem--) {
    if (e_create_matrix(A->rows - 1, A->columns - 1, &minor) == OK) {
      minor_filling(&minor, A, current_elem);
      result->matrix[0][current_elem] =
          minor.matrix[0][0] * minor.matrix[1][1] -
          minor.matrix[0][1] * minor.matrix[1][0];
    }
  }
  return 0;
}
