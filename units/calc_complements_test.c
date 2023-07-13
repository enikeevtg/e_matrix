#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(calc_complements_INCORRECT_STRUCT) {
  // Arrange
  // test_matrix pointer
  matrix_t* test_matrix_ptr = NULL;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(test_matrix_ptr, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_INCORRECT_MATRIX) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_INCORRECT_ROWS_0) {
  // Arrange
  // test_matrix
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_INCORRECT_ROWS_MIN) {
  // Arrange
  // test_matrix
  int rows = INT_MIN;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_INCORRECT_COLS_0) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_INCORRECT_COLS_MIN) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = INT_MIN;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_calc_complements(&test_matrix, &result_matrix);
  e_remove_matrix(&test_matrix);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(complements_matrix_OK_0) {
  // Arrange
  // test_matrix
  int rows = 5;
  int cols = 5;
  matrix_t test_matrix = {0};
  e_create_matrix(rows, cols, &test_matrix);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 5;
  int ref_cols = 5;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);

  // Act
  e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(complements_matrix_OK_1) {
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
  matrix_filling(ref_rows, ref_cols, &ref_matrix, INDICES);

  // Act
  e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(complements_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 2;
  int cols = 2;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 2;
  int ref_cols = 2;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[4] = {4.f, -3.f, -2.f, 1.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(complements_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 3;
  int cols = 3;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 3;
  int ref_cols = 3;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);
  double tmp[9] = {-3.f, 6.f, -3.f, 6.f, -12.f, 6.f, -3.f, 6.f, -3.f};
  int i = ref_rows * ref_cols;
  while (i--) (*ref_matrix.matrix)[i] = tmp[i];

  // Act
  e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(complements_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 4;
  int cols = 4;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 4;
  int ref_cols = 4;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);

  // Act
  e_calc_complements(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

Suite* calc_complements(void) {
  Suite* s = suite_create("calc_complements function suite");

  TCase* calc_complements_errors =
      tcase_create("calc_complements with errors function tests");
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_STRUCT);
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_MATRIX);
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_ROWS_0);
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_ROWS_MIN);
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_COLS_0);
  tcase_add_test(calc_complements_errors, calc_complements_INCORRECT_COLS_MIN);
  tcase_add_test(calc_complements_errors, calc_complements_CALC_ERROR);
  suite_add_tcase(s, calc_complements_errors);

  TCase* calc_complements_positive =
      tcase_create("calc_complements function tests");
  tcase_add_test(calc_complements_positive, complements_matrix_OK_0);
  tcase_add_test(calc_complements_positive, complements_matrix_OK_1);
  tcase_add_test(calc_complements_positive, complements_matrix_OK_2);
  tcase_add_test(calc_complements_positive, complements_matrix_OK_3);
  tcase_add_test(calc_complements_positive, complements_matrix_OK_4);
  suite_add_tcase(s, calc_complements_positive);

  return s;
}

int main(void) {
  Suite* calc_complements_suite = calc_complements();
  SRunner* runner = srunner_create(calc_complements_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
