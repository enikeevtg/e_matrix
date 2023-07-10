/**
 * @brief e_matrix.h internal functions
 */

#include "../e_matrix.h"

/// @brief matrix filling
/// @param rows
/// @param columns
/// @param A is matrix pointer
/// @return error_code from create_matrix function
int simple_filling(int rows, int columns, matrix_t* A, int mode) {
  int error_code = e_create_matrix(rows, columns, A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      if (mode == 1)
        A->matrix[i][j] = 10 * (i + 1) + j + 1;
      else if (mode == 2)
        A->matrix[i][j] = pow((i + j), 2);
      else if (mode == 3)
        A->matrix[i][j] = (double)(rand() % 11);
    }
  return error_code;
}

/// @brief matrix validity checking
/// @param A is matrix pointer
/// @return result of checking
int valid_matrix(matrix_t* A) {
  int valid = TRUE;
  if (A->matrix == NULL || A->rows < 1 || A->columns < 1) valid = FALSE;
  return valid;
}

/// @brief matrix printing function
/// @version v.3
/// @param A is matrix pointer
void print_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) printf(" %.0lf", A->matrix[i][j]);
    printf("\n");
  }
}

/// @brief matrix printing function
/// @version v.2
/// @param A is matrix pointer
void print_matrix_v2(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++)
      printf(" %.0lf", *(*(A->matrix + i) + j));
    printf("\n");
  }
}

/// @brief matrix printing function
/// @version v.1
/// @param A is matrix pointer
void print_matrix_inline(matrix_t* A) {
  int i = A->rows * A->columns;
  while (i--) printf(" %.0lf", *(*A->matrix + i));
  printf("\n");
}
