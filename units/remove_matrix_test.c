#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

START_TEST(remove_matrix_INCORRECT_STRUCT) {
  // Arrange
  matrix_t* test_matrix_ptr = NULL;
  // Act
  int error = e_remove_matrix(test_matrix_ptr);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_MATRIX) {
  // Arrange
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix = {NULL, rows_A, cols_A};
  // Act
  int error = e_remove_matrix(&test_matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_ROWS_A_0) {
  // Arrange
  int rows_A = 0;
  int cols_A = 11;
  matrix_t test_matrix = {NULL, rows_A, cols_A};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // Act
  int error = e_remove_matrix(&test_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_ROWS_A_MIN) {
  // Arrange
  int rows_A = INT_MIN;
  int cols_A = 11;
  matrix_t test_matrix = {NULL, rows_A, cols_A};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // Act
  int error = e_remove_matrix(&test_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_COLUMNS_0) {
  // Arrange
  int rows_A = 11;
  int cols_A = 0;
  matrix_t test_matrix = {NULL, rows_A, cols_A};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // Act
  int error = e_remove_matrix(&test_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_COLUMNS_MIN) {
  // Arrange
  int rows_A = 11;
  int cols_A = INT_MIN;
  matrix_t test_matrix = {NULL, rows_A, cols_A};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // Act
  int error = e_remove_matrix(&test_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_OK) {
  // Arrange
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix = {0};
  // Act
  e_create_matrix(rows_A, cols_A, &test_matrix);
  int error = e_remove_matrix(&test_matrix);
  // Assert
  ck_assert_int_eq(error, OK);
}
END_TEST

Suite* remove_matrix(void) {
  Suite* s = suite_create("remove_matrix function suite");
  TCase* remove_matrix = tcase_create("remove_matrix function tests");

  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_STRUCT);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_MATRIX);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_ROWS_A_0);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_ROWS_A_MIN);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_COLUMNS_0);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_COLUMNS_MIN);
  tcase_add_test(remove_matrix, remove_matrix_OK);
  suite_add_tcase(s, remove_matrix);

  return s;
}

int main(void) {
  Suite* remove_matrix_suite = remove_matrix();
  SRunner* runner = srunner_create(remove_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n\033[0m", failed);

  return failed ? 1 : 0;
}
