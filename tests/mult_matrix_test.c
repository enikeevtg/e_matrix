#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(mult_matrix_INCORRECT_STRUCT_A) {
  // Arrange
  // matrix A pointer
  matrix_t* matrix_A_ptr = NULL;
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(matrix_A_ptr, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_STRUCT_B) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B pointer
  matrix_t* matrix_B_ptr = NULL;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, matrix_B_ptr, &result_matrix);
  e_remove_matrix(&matrix_A);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_MATRIX_A) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {NULL, rows_A, cols_A};
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_MATRIX_B) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {NULL, rows_B, cols_B};
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_ROWS_A_0) {
  // Arrange
  // matrix A
  int rows_A = 0;
  int cols_A = 11;
  matrix_t matrix_A = {NULL, rows_A, cols_A};
  matrix_A.matrix = (double**)calloc(1, sizeof(double*));
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_ROWS_A_MIN) {
  // Arrange
  // matrix A
  int rows_A = INT_MIN;
  int cols_A = 11;
  matrix_t matrix_A = {NULL, rows_A, cols_A};
  matrix_A.matrix = (double**)calloc(1, sizeof(double*));
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_COLS_A_0) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 0;
  matrix_t matrix_A = {NULL, rows_A, cols_A};
  matrix_A.matrix = (double**)calloc(1, sizeof(double*));
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_COLS_A_MIN) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = INT_MIN;
  matrix_t matrix_A = {NULL, rows_A, cols_A};
  matrix_A.matrix = (double**)calloc(1, sizeof(double*));
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_ROWS_B_0) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 0;
  int cols_B = 11;
  matrix_t matrix_B = {NULL, rows_B, cols_B};
  matrix_B.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_ROWS_B_MIN) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = INT_MIN;
  int cols_B = 11;
  matrix_t matrix_B = {NULL, rows_B, cols_B};
  matrix_B.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_COLS_B_0) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 0;
  matrix_t matrix_B = {NULL, rows_B, cols_B};
  matrix_B.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_INCORRECT_COLS_B_MIN) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = INT_MIN;
  matrix_t matrix_B = {NULL, rows_B, cols_B};
  matrix_B.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 8;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(pos_mult_line_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 1;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 1;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 1;
  int ref_cols = 1;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  ref_matrix.matrix[0][0] = 14;

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_line_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 1;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 1;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {1.f, 2.f, 3.f, 2.f, 4.f, 6.f, 3.f, 6.f, 9.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_sqr_matrix_OK_3) {
  // Arrange
  // matrix A
  int rows_A = 2;
  int cols_A = 2;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 2;
  int cols_B = 2;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[4] = {7.f, 10.f, 15.f, 22.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_sqr_matrix_OK_4) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {30.f, 36.f, 42.f, 66.f, 81.f, 96.f, 102.f, 126.f, 150.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_5) {
  // Arrange
  // matrix A
  int rows_A = 2;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 2;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[4] = {22.f, 28.f, 49.f, 64.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_6) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 2;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 2;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {9.f, 12.f, 15.f, 19.f, 26.f, 33.f, 29.f, 40.f, 51.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

/*===========================negative result tests============================*/

START_TEST(neg_mult_line_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 1;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 1;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 1;
  int ref_cols = 1;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  ref_matrix.matrix[0][0] = -14;

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_line_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 1;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 1;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {-1.f, -2.f, -3.f, -2.f, -4.f, -6.f, -3.f, -6.f, -9.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_sqr_matrix_OK_3) {
  // Arrange
  // matrix A
  int rows_A = 2;
  int cols_A = 2;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 2;
  int cols_B = 2;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[4] = {-7.f, -10.f, -15.f, -22.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_sqr_matrix_OK_4) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {-30.f, -36.f,  -42.f,  -66.f, -81.f,
                   -96.f, -102.f, -126.f, -150.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_5) {
  // Arrange
  // matrix A
  int rows_A = 2;
  int cols_A = 3;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 3;
  int cols_B = 2;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[4] = {-22.f, -28.f, -49.f, -64.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_6) {
  // Arrange
  // matrix A
  int rows_A = 3;
  int cols_A = 2;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 2;
  int cols_B = 3;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {-9.f,  -12.f, -15.f, -19.f, -26.f,
                   -33.f, -29.f, -40.f, -51.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];
  (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_mult_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

Suite* mult_matrix(void) {
  Suite* s = suite_create("mult_matrix function suite");

  TCase* mult_matrix_errors =
      tcase_create("mult_matrix with errors function tests");
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_STRUCT_A);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_STRUCT_B);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_MATRIX_A);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_MATRIX_B);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_ROWS_A_0);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_ROWS_A_MIN);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_COLS_A_0);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_COLS_A_MIN);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_ROWS_B_0);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_ROWS_B_MIN);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_COLS_B_0);
  tcase_add_test(mult_matrix_errors, mult_matrix_INCORRECT_COLS_B_MIN);
  tcase_add_test(mult_matrix_errors, mult_matrix_CALC_ERROR);
  suite_add_tcase(s, mult_matrix_errors);

  TCase* mult_matrix_positive = tcase_create("mult_matrix > 0 function tests");
  tcase_add_test(mult_matrix_positive, pos_mult_line_matrix_OK_1);
  tcase_add_test(mult_matrix_positive, pos_mult_line_matrix_OK_2);
  tcase_add_test(mult_matrix_positive, pos_mult_sqr_matrix_OK_3);
  tcase_add_test(mult_matrix_positive, pos_mult_sqr_matrix_OK_4);
  tcase_add_test(mult_matrix_positive, pos_mult_rect_matrix_OK_5);
  tcase_add_test(mult_matrix_positive, pos_mult_rect_matrix_OK_6);
  suite_add_tcase(s, mult_matrix_positive);

  TCase* mult_matrix_negative = tcase_create("mult_matrix > 0 function tests");
  tcase_add_test(mult_matrix_negative, neg_mult_line_matrix_OK_1);
  tcase_add_test(mult_matrix_negative, neg_mult_line_matrix_OK_2);
  tcase_add_test(mult_matrix_negative, neg_mult_sqr_matrix_OK_3);
  tcase_add_test(mult_matrix_negative, neg_mult_sqr_matrix_OK_4);
  tcase_add_test(mult_matrix_negative, neg_mult_rect_matrix_OK_5);
  tcase_add_test(mult_matrix_negative, neg_mult_rect_matrix_OK_6);
  suite_add_tcase(s, mult_matrix_negative);

  return s;
}

int main(void) {
  Suite* mult_matrix_suite = mult_matrix();
  SRunner* runner = srunner_create(mult_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
