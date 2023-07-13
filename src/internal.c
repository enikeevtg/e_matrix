/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix structure initialization by nill values
/// @param A matrix pointer
void matrix_init(matrix_t* A) {
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

/// @brief matrix filling
/// @param rows
/// @param columns
/// @param A matrix pointer
/// @return error_code from create_matrix function
int matrix_filling(int rows, int columns, matrix_t* A, int mode) {
  int error = e_create_matrix(rows, columns, A);
  if (mode == POS_SIMPLE_SEQUENCE) {
    int i = A->rows * A->columns;
    while (i--) A->matrix[0][i] = i + 1;
  } else if (mode == NEG_SIMPLE_SEQUENCE) {
    int i = -A->rows * A->columns;
    while (i++) A->matrix[0][-i] = i - 1;
  } else if (mode == POS_SIMPLE_SEQUENCE_X2) {
    int i = A->rows * A->columns;
    while (i--) A->matrix[0][i] = 2 * (i + 1);
  } else if (mode == NEG_SIMPLE_SEQUENCE_X2) {
    int i = -A->rows * A->columns;
    while (i++) A->matrix[0][-i] = 2 * (i - 1);
  } else if (mode == POS_SIMPLE_SEQUENCE_T) {
    double elem = 1.f;
    for (int j = 0; j < columns; j++)
      for (int i = 0; i < rows; i++, elem++) A->matrix[i][j] = elem;
  } else if (mode == NEG_SIMPLE_SEQUENCE_T) {
    double elem = 1.f;
    for (int j = 0; j < columns; j++)
      for (int i = 0; i < rows; i++, elem++) A->matrix[i][j] = -elem;
  } else {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) {
        if (mode == INDICES) A->matrix[i][j] = 10 * (i + 1) + j + 1;
        // else if (mode == SQUARES)
        //   A->matrix[i][j] = pow((i + j), 2);
        // else if (mode == RANDOM)
        //   A->matrix[i][j] = (double)(rand() % 11);
      }
  }
  return error;
}

/// @brief matrix validity checking
/// @param A matrix pointer
/// @return result of checking: valid matrix - TRUE 1, invalid matrix - FALSE 0
int valid_matrix(matrix_t* A) {
  int valid = TRUE;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    valid = FALSE;
  return valid;
}

/// @brief summation and subtitution common function
/// @param A matrix pointer
/// @param B matrix pointer
/// @param result result matrix pointer
/// @param mode summation or subtitution toggle
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int sum_or_sub(matrix_t* A, matrix_t* B, matrix_t* result, int mode) {
  matrix_init(result);
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, A->columns, result)) return CALCULATION_ERROR;

  int i = A->rows * A->columns;
  if (mode == SUMMATION)
    while (i--) result->matrix[0][i] = A->matrix[0][i] + B->matrix[0][i];
  else if (mode == SUBTRACTION)
    while (i--) result->matrix[0][i] = A->matrix[0][i] - B->matrix[0][i];
  return OK;
}

/// @brief minor creating function
/// @version v.3
/// @param minor minor matrix
/// @param A source matrix
/// @param inline_position position of target element
int create_minor(matrix_t* minor, matrix_t* A, int inline_position) {
  int size = A->rows - 1;
  int error = e_create_matrix(size, size, minor);

  if (!error) {
    int minor_length = minor->rows * minor->columns;
    int current_row = inline_position / A->columns;
    int current_column = inline_position % A->columns;
    int k = 0;  // A matrix inline index
    for (int i = 0; i < minor_length; i++, k++) {
      if (k % A->columns == current_column) k++;
      if (k / A->columns == current_row) k += A->columns;
      minor->matrix[0][i] = A->matrix[0][k];
    }
  }
  return error;
}
