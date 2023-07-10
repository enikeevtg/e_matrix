/**
 * @brief matrices multiplication
 * @param A is matrix pointer
 * @param B is matrix pointer
 * @param result is result matrix pointer
 * @return error code
 */

#include "../e_matrix.h"

int e_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, B->columns, result)) return CALCULATION_ERROR;

  for (int k = 0; k < B->columns; k++)  // result column index
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
      }
    }
  return OK;
}
