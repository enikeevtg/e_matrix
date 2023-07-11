#ifndef E_MATRIX_E_MATRIX_H_
#define E_MATRIX_E_MATRIX_H_

// INCLUDES
#include <math.h>
#include <stdio.h>
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
#define PRECISION 0.0000001
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0

#define SUMMATION 1
#define SUBTRACTION -1

// FUNCTIONS
int e_create_matrix(int rows, int columns, matrix_t* result);
int e_remove_matrix(matrix_t* A);
int e_eq_matrix(matrix_t* A, matrix_t* B);
int e_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int e_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int e_mult_number(matrix_t* A, double number, matrix_t* result);
int e_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int e_transpose(matrix_t* A, matrix_t* result);
int e_calc_complements(matrix_t* A, matrix_t* result);
int e_determinant(matrix_t* A, double* result);
int e_inverse_matrix(matrix_t* A, matrix_t* result);

// INTERNAL
int simple_filling(int rows, int columns, matrix_t* A, int mode);
int valid_matrix(matrix_t* A);
int sum_or_sub(matrix_t* A, matrix_t* B, matrix_t* result, int mode);
void minor_filling(matrix_t* dest, matrix_t* src, int inline_position);
void print_matrix(matrix_t* A);
void print_matrix_v2(matrix_t* A);
void print_matrix_inline(matrix_t* A);

#endif  // E_MATRIX_E_MATRIX_H_
