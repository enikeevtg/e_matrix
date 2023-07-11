#include <check.h>

#include "../e_matrix.h"

START_TEST(eq_matrix_SUCCESS) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // Act
  int match = e_eq_matrix(&test_matrix_A, &test_matrix_B);
  // Assert
  ck_assert_int_eq(match, SUCCESS);
  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
}
END_TEST

START_TEST(eq_matrix_FAILURE_ROWS) {
  // Arrange
  // matrix A
  int rows_A = 1;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // Act
  int match = e_eq_matrix(&test_matrix_A, &test_matrix_B);
  // Assert
  ck_assert_int_eq(match, FAILURE);
  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
}
END_TEST

START_TEST(eq_matrix_FAILURE_COLUMNS) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 1;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // Act
  int match = e_eq_matrix(&test_matrix_A, &test_matrix_B);
  // Assert
  ck_assert_int_eq(match, FAILURE);
  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
}
END_TEST

START_TEST(eq_matrix_FAILURE) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 8;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 8;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, INDICES);
  // Act
  int match = e_eq_matrix(&test_matrix_A, &test_matrix_B);
  // Assert
  ck_assert_int_eq(match, FAILURE);
  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
}
END_TEST

Suite* eq_matrix(void) {
  Suite* s = suite_create("eq_matrix function suite");
  TCase* eq_matrix = tcase_create("eq_matrix function tests");

  tcase_add_test(eq_matrix, eq_matrix_SUCCESS);
  tcase_add_test(eq_matrix, eq_matrix_FAILURE_ROWS);
  tcase_add_test(eq_matrix, eq_matrix_FAILURE_COLUMNS);
  tcase_add_test(eq_matrix, eq_matrix_FAILURE);
  suite_add_tcase(s, eq_matrix);

  return s;
}

int main(void) {
  Suite* eq_matrix_suite = eq_matrix();
  SRunner* runner = srunner_create(eq_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
