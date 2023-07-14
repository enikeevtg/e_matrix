#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(determinant_INCORRECT_STRUCT) {
  // Arrange
  // test_matrix pointer
  matrix_t* test_matrix_ptr = NULL;
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(test_matrix_ptr, &det);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_MATRIX) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_ROWS_0) {
  // Arrange
  // test_matrix
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_ROWS_MIN) {
  // Arrange
  // test_matrix
  int rows = INT_MIN;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_COLS_0) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_INCORRECT_COLS_MIN) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = INT_MIN;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result value
  double det = 0.f;

  // Act
  int error = e_determinant(&test_matrix, &det);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

/*==========================non error result tests===========================*/

START_TEST(determinant_OK_0) {
  // Arrange
  // test_matrix
  int rows = 2;
  int cols = 2;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  // result value
  double det = 0.f;
  // reference value
  double ref_det = 0.f;

  // Act
  e_determinant(&test_matrix, &det);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_double_eq(det, ref_det);
}
END_TEST

START_TEST(determinant_OK_11) {
  // Arrange
  // test_matrix
  int rows = 1;
  int cols = 1;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, INDICES);
  // result value
  double det = 0.f;
  // reference value
  double ref_det = 11.f;

  // Act
  e_determinant(&test_matrix, &det);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_double_eq(det, ref_det);
}
END_TEST

START_TEST(determinant_OK_2) {
  // Arrange
  // test_matrix
  int rows = 2;
  int cols = 2;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  double tmp[4] = {10.f, -7.f, 0.f, 6.f};
  int i = rows * cols;
  while (i--) (*test_matrix.matrix)[i] = tmp[i];
  // result value
  double det = 0.f;
  // reference value
  double ref_det = 60.f;

  // Act
  e_determinant(&test_matrix, &det);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_double_eq(det, ref_det);
}
END_TEST

START_TEST(determinant_OK_3) {
  // Arrange
  // test_matrix
  int rows = 3;
  int cols = 3;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  double tmp[9] = {2.f, 5.f, 7.f, 6.f, 3.f, 4.f, 5.f, -2.f, -3.f};
  int i = rows * cols;
  while (i--) (*test_matrix.matrix)[i] = tmp[i];
  // result value
  double det = 0.f;
  // reference value
  double ref_det = -1.f;

  // Act
  e_determinant(&test_matrix, &det);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_double_eq(det, ref_det);
}
END_TEST

START_TEST(determinant_OK_4) {
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
  // result value
  double det = 0.f;
  // reference value
  double ref_det = -2.f;

  // Act
  e_determinant(&test_matrix, &det);

  // Assert
  ck_assert_double_eq(det, ref_det);

  e_remove_matrix(&test_matrix);
}
END_TEST

Suite* determinant(void) {
  Suite* s = suite_create("determinant function suite");

  TCase* determinant_errors =
      tcase_create("determinant with errors function tests");
  tcase_add_test(determinant_errors, determinant_INCORRECT_STRUCT);
  tcase_add_test(determinant_errors, determinant_INCORRECT_MATRIX);
  tcase_add_test(determinant_errors, determinant_INCORRECT_ROWS_0);
  tcase_add_test(determinant_errors, determinant_INCORRECT_ROWS_MIN);
  tcase_add_test(determinant_errors, determinant_INCORRECT_COLS_0);
  tcase_add_test(determinant_errors, determinant_INCORRECT_COLS_MIN);
  tcase_add_test(determinant_errors, determinant_CALC_ERROR);
  suite_add_tcase(s, determinant_errors);

  TCase* determinant_positive = tcase_create("determinant function tests");
  tcase_add_test(determinant_positive, determinant_OK_0);
  tcase_add_test(determinant_positive, determinant_OK_11);
  tcase_add_test(determinant_positive, determinant_OK_2);
  tcase_add_test(determinant_positive, determinant_OK_3);
  tcase_add_test(determinant_positive, determinant_OK_4);
  suite_add_tcase(s, determinant_positive);

  return s;
}

int main(void) {
  Suite* determinant_suite = determinant();
  SRunner* runner = srunner_create(determinant_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n\033[0m", failed);

  return failed ? 1 : 0;
}
