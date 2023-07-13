#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(transpose_INCORRECT_STRUCT) {
  // Arrange
  // test_matrix pointer
  matrix_t* test_matrix_ptr = NULL;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(test_matrix_ptr, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_INCORRECT_MATRIX) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(&test_matrix, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_INCORRECT_ROWS_0) {
  // Arrange
  // test_matrix
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_INCORRECT_ROWS_MIN) {
  // Arrange
  // test_matrix
  int rows = INT_MIN;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_INCORRECT_COLS_0) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_INCORRECT_COLS_MIN) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = INT_MIN;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_transpose(&test_matrix, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(pos_transp_sqr_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_transp_rect_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 8;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_transp_rect_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 8;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

/*===========================negative result tests============================*/

START_TEST(neg_transp_sqr_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_transp_rect_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 8;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_transp_rect_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 8;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_T);

  // Act
  e_transpose(&test_matrix, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

Suite* transpose(void) {
  Suite* s = suite_create("transpose function suite");

  TCase* transpose_errors =
      tcase_create("transpose with errors function tests");
  tcase_add_test(transpose_errors, transpose_INCORRECT_STRUCT);
  tcase_add_test(transpose_errors, transpose_INCORRECT_MATRIX);
  tcase_add_test(transpose_errors, transpose_INCORRECT_ROWS_0);
  tcase_add_test(transpose_errors, transpose_INCORRECT_ROWS_MIN);
  tcase_add_test(transpose_errors, transpose_INCORRECT_COLS_0);
  tcase_add_test(transpose_errors, transpose_INCORRECT_COLS_MIN);
  suite_add_tcase(s, transpose_errors);

  TCase* transpose_positive =
      tcase_create("transpose result > 0 function tests");
  tcase_add_test(transpose_positive, pos_transp_sqr_matrix_OK_1);
  tcase_add_test(transpose_positive, pos_transp_rect_matrix_OK_2);
  tcase_add_test(transpose_positive, pos_transp_rect_matrix_OK_3);
  suite_add_tcase(s, transpose_positive);

  TCase* transpose_negative =
      tcase_create("transpose result < 0 function tests");
  tcase_add_test(transpose_negative, neg_transp_sqr_matrix_OK_1);
  tcase_add_test(transpose_negative, neg_transp_rect_matrix_OK_2);
  tcase_add_test(transpose_negative, neg_transp_rect_matrix_OK_3);
  suite_add_tcase(s, transpose_negative);

  return s;
}

int main(void) {
  Suite* transpose_suite = transpose();
  SRunner* runner = srunner_create(transpose_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
