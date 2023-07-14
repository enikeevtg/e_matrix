#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(sum_matrix_INCORRECT_STRUCT_A) {
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
  int error = e_sum_matrix(matrix_A_ptr, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_STRUCT_B) {
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
  int error = e_sum_matrix(&matrix_A, matrix_B_ptr, &result_matrix);
  e_remove_matrix(&matrix_A);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_MATRIX_A) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_MATRIX_B) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_ROWS_A_0) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_ROWS_A_MIN) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_COLS_A_0) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_COLS_A_MIN) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  free(matrix_A.matrix);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_ROWS_B_0) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_ROWS_B_MIN) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_COLS_B_0) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_INCORRECT_COLS_B_MIN) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  free(matrix_B.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_CALC_ERROR_ROWS) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

START_TEST(sum_matrix_CALC_ERROR_COLS) {
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
  int error = e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);
  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(pos_sum_sqr_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(pos_sum_sqr_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE_X2);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, POS_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(pos_sum_rect_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(pos_sum_rect_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, POS_SIMPLE_SEQUENCE_X2);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, POS_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

/*===========================negative result tests============================*/

START_TEST(neg_sum_sqr_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(neg_sum_sqr_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE_X2);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, NEG_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(neg_sum_rect_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(neg_sum_rect_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE_X2);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &matrix_REF, NEG_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

/*===========================nill result tests============================*/

START_TEST(nill_sum_sqr_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  e_create_matrix(rows_REF, cols_REF, &matrix_REF);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

START_TEST(nill_sum_rect_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t matrix_A = {0};
  matrix_filling(rows_A, cols_A, &matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t matrix_B = {0};
  matrix_filling(rows_B, cols_B, &matrix_B, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t matrix_REF = {0};
  e_create_matrix(rows_REF, cols_REF, &matrix_REF);

  // Act
  e_sum_matrix(&matrix_A, &matrix_B, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&matrix_A);
  e_remove_matrix(&matrix_B);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&matrix_REF);
}
END_TEST

Suite* sum_matrix(void) {
  Suite* s = suite_create("sum_matrix function suite");

  TCase* sum_matrix_errors =
      tcase_create("sum_matrix with errors function tests");
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_STRUCT_A);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_STRUCT_B);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_MATRIX_A);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_MATRIX_B);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_ROWS_A_0);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_ROWS_A_MIN);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_COLS_A_0);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_COLS_A_MIN);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_ROWS_B_0);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_ROWS_B_MIN);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_COLS_B_0);
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_COLS_B_MIN);
  tcase_add_test(sum_matrix_errors, sum_matrix_CALC_ERROR_ROWS);
  tcase_add_test(sum_matrix_errors, sum_matrix_CALC_ERROR_COLS);
  suite_add_tcase(s, sum_matrix_errors);

  TCase* sum_matrix_positive = tcase_create("sum_matrix > 0 function tests");
  tcase_add_test(sum_matrix_positive, pos_sum_sqr_matrix_OK_1);
  tcase_add_test(sum_matrix_positive, pos_sum_sqr_matrix_OK_2);
  tcase_add_test(sum_matrix_positive, pos_sum_rect_matrix_OK_1);
  tcase_add_test(sum_matrix_positive, pos_sum_rect_matrix_OK_2);
  suite_add_tcase(s, sum_matrix_positive);

  TCase* sum_matrix_negative = tcase_create("sum_matrix < 0 function tests");
  tcase_add_test(sum_matrix_negative, neg_sum_sqr_matrix_OK_1);
  tcase_add_test(sum_matrix_negative, neg_sum_sqr_matrix_OK_2);
  tcase_add_test(sum_matrix_negative, neg_sum_rect_matrix_OK_1);
  tcase_add_test(sum_matrix_negative, neg_sum_rect_matrix_OK_2);
  suite_add_tcase(s, sum_matrix_negative);

  TCase* sum_matrix_0 = tcase_create("sum_matrix == 0 function tests");
  tcase_add_test(sum_matrix_0, nill_sum_sqr_matrix_OK);
  tcase_add_test(sum_matrix_0, nill_sum_rect_matrix_OK);
  suite_add_tcase(s, sum_matrix_0);

  return s;
}

int main(void) {
  Suite* sum_matrix_suite = sum_matrix();
  SRunner* runner = srunner_create(sum_matrix_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n\033[0m", failed);

  return failed ? 1 : 0;
}
