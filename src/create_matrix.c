/**
 * @brief
 * @warning must remove_matrix calling after working
 * @param rows
 * @param columns
 * @param result
 * @return error code
 */

#include "../e_matrix.h"

int e_create_matrix(int rows, int columns, matrix_t* result) {
  if (rows < 1 || columns < 1) return INCORRECT_MATRIX;

  result->matrix = (double**)calloc(
      rows * sizeof(double*) + rows * columns * sizeof(double), 1);
  double* first_elem =
      (double*)((char*)result->matrix + rows * sizeof(double*));
  for (int i = 0; i < rows; i++) *(result->matrix + i) = first_elem + i * rows;
  result->rows = rows;
  result->columns = columns;
  return OK;
}
