/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrices multiplication
/// @version v.2
/// @param A matrix pointer
/// @param B matrix pointer
/// @param result result matrix pointer
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  matrix_init(result);
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, B->columns, result)) return CALCULATION_ERROR;

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      for (int k = 0; k < A->columns; k++) {  // result column index
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}

/// @version v.1
int e_mult_matrix_v1(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!valid_matrix(A) || !valid_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;
  if (e_create_matrix(A->rows, B->columns, result)) return CALCULATION_ERROR;

  for (int k = 0; k < B->columns; k++) {  // result column index
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
      }
    }
  }
  return OK;
}
