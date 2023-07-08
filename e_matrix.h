#ifndef E_MATRIX_E_MATRIX_H_
#define E_MATRIX_E_MATRIX_H_

// INCLUDES
#include <math.h>
#include <stdlib.h>

// TYPES
typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

// MACROS
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

// FUNCTIONS
int e_create_matrix(int rows, int columns, matrix_t* result);

#endif  // E_MATRIX_E_MATRIX_H_
