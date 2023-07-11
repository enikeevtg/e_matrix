/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrix filling
/// @param rows
/// @param columns
/// @param A matrix pointer
/// @return error_code from create_matrix function
int matrix_filling(int rows, int columns, matrix_t* A, int mode) {
  int error_code = e_create_matrix(rows, columns, A);
  if (mode == SIMPLE_SEQUENCE) {
    int i = A->rows * A->columns;
    while (i--) A->matrix[0][i] = i + 1;
  } else {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) {
        if (mode == INDICES)
          A->matrix[i][j] = 10 * (i + 1) + j + 1;
        else if (mode == SQUARES)
          A->matrix[i][j] = pow((i + j), 2);
        else if (mode == RANDOM)
          A->matrix[i][j] = (double)(rand() % 11);
      }
  }

  return error_code;
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

/// @brief minor filling function
/// @param dest minor matrix
/// @param src source matrix
/// @param inline_position position of target element
void minor_filling(matrix_t* dest, matrix_t* src, int inline_position) {
  int dest_length = dest->rows * dest->columns;
  int current_row = inline_position / src->columns;
  int current_column = inline_position % src->columns;
  int k = 0;  // src matrix inline index
  for (int i = 0; i < dest_length; i++, k++) {
    if (k % src->columns == current_column) k++;
    if (k / src->columns == current_row) k += src->columns;
    dest->matrix[0][i] = src->matrix[0][k];
  }
}

/// @brief minor filling function
/// @version v.2
/// @param dest minor matrix
/// @param src source matrix
/// @param inline_position position of target element
void minor_filling_v2(matrix_t* dest, matrix_t* src, int inline_position) {
  int src_length = src->rows * src->columns;
  int current_row = inline_position / src->columns;
  int current_column = inline_position % src->columns;
  int src_i = 0;   // src matrix inline index
  int dest_i = 0;  // dest matrix inline index
  while (src_i < src_length) {
    // coditions version 1:
    if (src_i / src->columns == current_row)
      src_i += src->columns;
    else if (src_i % src->columns == current_column)
      src_i++;
    else {
      *(*(dest->matrix) + dest_i) = *(*(src->matrix) + src_i);
      dest_i++;
      src_i++;
    }
  }
  printf("M(%d, %d)\n", current_row + 1, current_column + 1);
  print_matrix(dest);
}

/// @brief matrix printing function
/// @version v.3
/// @param A matrix pointer
void print_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    printf("\t");
    for (int j = 0; j < A->columns; j++) printf(" %.0lf", A->matrix[i][j]);
    printf("\n");
  }
}

/// @brief matrix printing function
/// @version v.2
/// @param A matrix pointer
void print_matrix_v2(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++)
      printf(" %.0lf", *(*(A->matrix + i) + j));
    printf("\n");
  }
}

/// @brief matrix printing function
/// @version v.1
/// @param A matrix pointer
void print_matrix_inline(matrix_t* A) {
  int i = A->rows * A->columns;
  while (i--) printf(" %.0lf", *(*A->matrix + i));
  printf("\n");
}
