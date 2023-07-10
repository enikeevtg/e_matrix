/**
 * @brief matrix creating and nill-filling function
 * @warning must remove_matrix call after working
 * @param rows
 * @param columns
 * @param result is new matrix filled by nills
 * @return error code
 */

#include "../e_matrix.h"

int e_create_matrix(int rows, int columns, matrix_t* result) {
  result->matrix = NULL;
  // result->rows = 0;
  // result->columns = 0;
  if (rows < 1 || columns < 1) return INCORRECT_MATRIX;

  size_t array_size = rows * sizeof(double*) + rows * columns * sizeof(double);
  result->matrix = (double**)calloc(array_size, 1);
  if (result->matrix == NULL) return CALCULATION_ERROR;

  double* ptr_11 = (double*)(result->matrix + rows);
  for (int i = 0; i < rows; i++) *(result->matrix + i) = ptr_11 + i * columns;
  result->rows = rows;
  result->columns = columns;
  return OK;
}
