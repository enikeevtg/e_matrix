#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(mult_number_INCORRECT_STRUCT) {
  // Arrange
  // test_matrix pointer
  matrix_t* test_matrix_ptr = NULL;
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(test_matrix_ptr, scalar, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_INCORRECT_MATRIX) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_INCORRECT_ROWS_0) {
  // Arrange
  // test_matrix
  int rows = 0;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(&test_matrix, scalar, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_INCORRECT_ROWS_MIN) {
  // Arrange
  // test_matrix
  int rows = INT_MIN;
  int cols = 11;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(&test_matrix, scalar, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_INCORRECT_COLS_0) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 0;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(&test_matrix, scalar, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_number_INCORRECT_COLS_MIN) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = INT_MIN;
  matrix_t test_matrix = {NULL, rows, cols};
  test_matrix.matrix = (double**)calloc(1, sizeof(double*));
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};

  // Act
  int error = e_mult_number(&test_matrix, scalar, &result_matrix);
  if (test_matrix.matrix) free(test_matrix.matrix);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(pos_mult_sqr_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_sqr_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_sqr_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = -1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_sqr_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = -2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = -1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(pos_mult_rect_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = -2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

/*===========================negative result tests============================*/

START_TEST(neg_mult_sqr_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = -1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_sqr_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = -2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_sqr_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_sqr_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = 2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_1) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = -1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_2) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = -2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_3) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = 1.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(neg_mult_rect_matrix_OK_4) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, NEG_SIMPLE_SEQUENCE);
  double scalar = 2.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  matrix_filling(ref_rows, ref_cols, &ref_matrix, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

/*===========================nill result tests============================*/

START_TEST(nill_mult_sqr_matrix_OK) {
  // Arrange
  // test_matrix
  int rows = 11;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 0.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 11;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

START_TEST(nill_mult_rect_matrix_OK) {
  // Arrange
  // test_matrix
  int rows = 8;
  int cols = 11;
  matrix_t test_matrix = {0};
  matrix_filling(rows, cols, &test_matrix, POS_SIMPLE_SEQUENCE);
  double scalar = 0.f;
  // result matrix
  matrix_t result_matrix = {0};
  // reference matrix
  int ref_rows = 8;
  int ref_cols = 11;
  matrix_t ref_matrix = {0};
  e_create_matrix(ref_rows, ref_cols, &ref_matrix);

  // Act
  e_mult_number(&test_matrix, scalar, &result_matrix);

  // Assert
  int match = e_eq_matrix(&result_matrix, &ref_matrix);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix);
  e_remove_matrix(&result_matrix);
  e_remove_matrix(&ref_matrix);
}
END_TEST

Suite* mult_number(void) {
  Suite* s = suite_create("mult_number function suite");

  TCase* mult_number_errors =
      tcase_create("mult_number with errors function tests");
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_STRUCT);
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_MATRIX);
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_ROWS_0);
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_ROWS_MIN);
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_COLS_0);
  tcase_add_test(mult_number_errors, mult_number_INCORRECT_COLS_MIN);
  suite_add_tcase(s, mult_number_errors);

  TCase* mult_number_positive =
      tcase_create("mult_number result > 0 function tests");
  tcase_add_test(mult_number_positive, pos_mult_sqr_matrix_OK_1);
  tcase_add_test(mult_number_positive, pos_mult_sqr_matrix_OK_2);
  tcase_add_test(mult_number_positive, pos_mult_sqr_matrix_OK_3);
  tcase_add_test(mult_number_positive, pos_mult_sqr_matrix_OK_4);
  tcase_add_test(mult_number_positive, pos_mult_rect_matrix_OK_1);
  tcase_add_test(mult_number_positive, pos_mult_rect_matrix_OK_2);
  tcase_add_test(mult_number_positive, pos_mult_rect_matrix_OK_3);
  tcase_add_test(mult_number_positive, pos_mult_rect_matrix_OK_4);
  suite_add_tcase(s, mult_number_positive);

  TCase* mult_number_negative =
      tcase_create("mult_number result < 0 function tests");
  tcase_add_test(mult_number_negative, neg_mult_sqr_matrix_OK_1);
  tcase_add_test(mult_number_negative, neg_mult_sqr_matrix_OK_2);
  tcase_add_test(mult_number_negative, neg_mult_sqr_matrix_OK_3);
  tcase_add_test(mult_number_negative, neg_mult_sqr_matrix_OK_4);
  tcase_add_test(mult_number_negative, neg_mult_rect_matrix_OK_1);
  tcase_add_test(mult_number_negative, neg_mult_rect_matrix_OK_2);
  tcase_add_test(mult_number_negative, neg_mult_rect_matrix_OK_3);
  tcase_add_test(mult_number_negative, neg_mult_rect_matrix_OK_4);
  suite_add_tcase(s, mult_number_negative);

  TCase* mult_number_0 = tcase_create("mult_number result == 0 function tests");
  tcase_add_test(mult_number_0, nill_mult_sqr_matrix_OK);
  tcase_add_test(mult_number_0, nill_mult_rect_matrix_OK);
  suite_add_tcase(s, mult_number_0);

  return s;
}

int main(void) {
  Suite* mult_number_suite = mult_number();
  SRunner* runner = srunner_create(mult_number_suite);

  srunner_run_all(runner, CK_NORMAL);
  int tests_count = srunner_ntests_run(runner);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
