/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix creating and nill-filling function
/// @warning must remove_matrix call after working
/// @param rows
/// @param columns
/// @param result new matrix filled by nills
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_create_matrix(int rows, int columns, matrix_t* result) {
  matrix_init(result);
  if (rows < 1 || columns < 1) return INCORRECT_MATRIX;

  size_t array_size = rows * sizeof(double*) + rows * columns * sizeof(double);
  result->matrix = (double**)calloc(array_size, 1);
  int error = CALCULATION_ERROR;
  if (result->matrix != NULL) {
    error = OK;
    double* ptr_11 = (double*)(result->matrix + rows);
    for (int i = 0; i < rows; i++) *(result->matrix + i) = ptr_11 + i * columns;
    result->rows = rows;
    result->columns = columns;
  }
  return error;
}
