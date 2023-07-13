#include "test.h"

/*================================error tests=================================*/

START_TEST(inverse_matrix_INCORRECT_STRUCT) {
  // Arrange
  // test_matrix pointer
  matrix_t* test_matrix_ptr = NULL;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(test_matrix_ptr, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_MATRIX) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_ROWS_0) {
  // Arrange
  // test_matrix
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_ROWS_MIN) {
  // Arrange
  // test_matrix
  int rows = INT_MIN;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_COLS_0) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_INCORRECT_COLS_MIN) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = INT_MIN;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(inverse_matrix_CALC_ERROR_DET_0) {
  // Arrange
  // test_matrix
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_inverse_matrix(&test_matrix, &result_matrix);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(inverse_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 1;
  int cols = 1;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, INDICES);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 1;
  int ref_cols = 1;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  **ref_matrix.matrix = 1 / **test_matrix.matrix;

  // Act
  e_inverse_matrix(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(inverse_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 2;
  int cols = 2;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  double tmp[4] = {10.f, -7.f, 0.f, 6.f};
  int i = rows * cols;
  while (i--) (*test_matrix.matrix)[i] = tmp[i];
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double ref_tmp[4] = {0.1f, 7.f / 60.f, 0.f, 1.f / 6.f};
  i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = ref_tmp[i];

  // Act
  e_inverse_matrix(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(inverse_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 3;
  int cols = 3;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  double tmp[9] = {2.f, 5.f, 7.f, 6.f, 3.f, 4.f, 5.f, -2.f, -3.f};
  int i = rows * cols;
  while (i--) (*test_matrix.matrix)[i] = tmp[i];
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double ref_tmp[9] = {1.f, -1.f, 1.f, -38.f, 41.f, -34.f, 27.f, -29.f, 24.f};
  i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = ref_tmp[i];

  // Act
  e_inverse_matrix(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(inverse_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 4;
  int cols = 4;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  double tmp[16] = {10.f, 1.f, 0.f, 6.f, -8.f, -3.f, 2.f, 0.f,
                    9.f,  4.f, 6.f, 6.f, 10.f, 5.f,  8.f, 7.f};
  int i = rows * cols;
  while (i--) (*test_matrix.matrix)[i] = tmp[i];
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 4;
  int ref_cols = 4;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double ref_tmp[16] = {-11.f,  3.f,  95.f,  -72.f, 21.f, -6.f, -182.f, 138.f,
                        -12.5f, 3.5f, 107.f, -81.f, 15.f, -4.f, -128.f, 97.f};
  i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = ref_tmp[i];

  // Act
  e_inverse_matrix(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

Suite* inverse_matrix(void) {
  Suite* s = suite_create("inverse_matrix function suite");

  TCase* inverse_matrix_errors =
      tcase_create("inverse_matrix with errors function tests");
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_STRUCT);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_MATRIX);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_ROWS_0);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_ROWS_MIN);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_COLS_0);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_INCORRECT_COLS_MIN);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_CALC_ERROR_DET_0);
  tcase_add_test(inverse_matrix_errors, inverse_matrix_CALC_ERROR);
  suite_add_tcase(s, inverse_matrix_errors);

  TCase* inverse_matrix_positive =
      tcase_create("inverse_matrix function tests");
  tcase_add_test(inverse_matrix_positive, inverse_matrix_OK_1);
  tcase_add_test(inverse_matrix_positive, inverse_matrix_OK_2);
  tcase_add_test(inverse_matrix_positive, inverse_matrix_OK_3);
  tcase_add_test(inverse_matrix_positive, inverse_matrix_OK_4);
  suite_add_tcase(s, inverse_matrix_positive);

  return s;
}
