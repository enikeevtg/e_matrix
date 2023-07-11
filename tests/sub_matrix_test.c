#include <check.h>

#include "../e_matrix.h"

START_TEST(sub_sqr_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE_PLUS);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // matrix sub_AB
  matrix_t test_matrix_SUB = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, SIMPLE_SEQUENCE);

  // Act
  e_sub_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUB);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUB, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUB);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(sub_rect_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE_PLUS);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // matrix sub_AB
  matrix_t test_matrix_SUB = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, SIMPLE_SEQUENCE);

  // Act
  e_sub_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUB);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUB, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUB);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(sub_matrix_INCORRECT_MATRIX) {
  // Arrange
  // matrix A
  int rows_A = 0;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // matrix sub_AB
  matrix_t test_matrix_SUB = {0};

  // Act
  int error = e_sub_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUB);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUB);
}
END_TEST

START_TEST(sub_matrix_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, SIMPLE_SEQUENCE);
  // matrix sub_AB
  matrix_t test_matrix_SUB = {0};

  // Act
  int error = e_sub_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUB);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUB);
}
END_TEST

Suite* sub_matrix(void) {
  Suite* s = suite_create("sub_matrix function suite");
  TCase* sub_matrix = tcase_create("sub_matrix function tests");

  tcase_add_test(sub_matrix, sub_sqr_matrix_OK);
  tcase_add_test(sub_matrix, sub_rect_matrix_OK);
  tcase_add_test(sub_matrix, sub_matrix_INCORRECT_MATRIX);
  tcase_add_test(sub_matrix, sub_matrix_CALC_ERROR);
  suite_add_tcase(s, sub_matrix);

  return s;
}

int main(void) {
  Suite* sub_matrix_suite = sub_matrix();
  SRunner* runner = srunner_create(sub_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
