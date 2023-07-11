#include <check.h>

#include "../e_matrix.h"

START_TEST(remove_matrix_OK) {
  // Arrange
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  // Act
  e_create_matrix(rows, cols, &test_matrix);
  int error = e_remove_matrix(&test_matrix);
  // Assert
  ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_ROWS) {
  // Arrange
  matrix_t test_matrix = {NULL, 0, 11};
  // Act
  int error = e_remove_matrix(&test_matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_matrix_INCORRECT_COLUMNS) {
  // Arrange
  matrix_t test_matrix = {NULL, 11, 0};
  // Act
  int error = e_remove_matrix(&test_matrix);
  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

Suite* remove_matrix(void) {
  Suite* s = suite_create("remove_matrix function suite");
  TCase* remove_matrix = tcase_create("remove_matrix function tests");

  tcase_add_test(remove_matrix, remove_matrix_OK);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_ROWS);
  tcase_add_test(remove_matrix, remove_matrix_INCORRECT_COLUMNS);
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
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
