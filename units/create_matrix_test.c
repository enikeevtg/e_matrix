#include <check.h>

#include "../e_matrix.h"

START_TEST(create_matrix_INCORRECT_STRUCT) {
  // Arrange
  int rows = 11;
  int cols = 1;
  matrix_t* test_matrix_ptr = NULL;
  // Act
  int error = e_create_matrix(rows, cols, test_matrix_ptr);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  e_remove_matrix(test_matrix_ptr);
}
END_TEST

START_TEST(create_matrix_INCORRECT_ROWS) {
  // Arrange
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {0};
  // Act
  int error = e_create_matrix(rows, cols, &test_matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  e_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(create_matrix_INCORRECT_COLUMNS) {
  // Arrange
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {0};
  // Act
  int error = e_create_matrix(rows, cols, &test_matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
  e_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(create_matrix_OK) {
  // Arrange
  int rows = 11;
  int cols = 1;
  matrix_t test_matrix = {0};
  // Act
  int error = e_create_matrix(rows, cols, &test_matrix);
  // Assert
  ck_assert_int_eq(error, OK);
  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, cols);
  e_remove_matrix(&test_matrix);
}
END_TEST

Suite* create_matrix(void) {
  Suite* s = suite_create("create_matrix function suite");

  TCase* create_matrix = tcase_create("create_matrix function tests");
  tcase_add_test(create_matrix, create_matrix_INCORRECT_STRUCT);
  tcase_add_test(create_matrix, create_matrix_INCORRECT_ROWS);
  tcase_add_test(create_matrix, create_matrix_INCORRECT_COLUMNS);
  tcase_add_test(create_matrix, create_matrix_OK);
  suite_add_tcase(s, create_matrix);

  return s;
}

int main(void) {
  Suite* create_matrix_suite = create_matrix();
  SRunner* runner = srunner_create(create_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n\033[0m", failed);

  return failed ? 1 : 0;
}
