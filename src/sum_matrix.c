/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../e_matrix.h"

/// @brief matrices adding
/// @version v.2
/// @param A is matrix pointer
/// @param B is matrix pointer
/// @param result is result matrix pointer
/// @return error code: OK 0, INCORRECT_MATRIX 1, CALCULATION_ERROR 2
int e_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return sum_or_sub(A, B, result, SUMMATION);
}
