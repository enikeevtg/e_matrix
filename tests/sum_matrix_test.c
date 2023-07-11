#include <check.h>

#include "../e_matrix.h"

/*================================error tests=================================*/

START_TEST(sum_matrix_INCORRECT_MATRIX) {
  // Arrange
  // matrix A
  int rows_A = 0;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};

  // Act
  int error = e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  ck_assert_int_eq(error, INCORRECT_MATRIX);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
}
END_TEST

START_TEST(sum_matrix_CALC_ERROR) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};

  // Act
  int error = e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  ck_assert_int_eq(error, CALCULATION_ERROR);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
}
END_TEST

/*===========================positive result tests============================*/

START_TEST(pos_sum_sqr_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(pos_sum_sqr_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE_X2);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, POS_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(pos_sum_rect_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, POS_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(pos_sum_rect_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, POS_SIMPLE_SEQUENCE_X2);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, POS_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

/*===========================negative result tests============================*/

START_TEST(neg_sum_sqr_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(neg_sum_sqr_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE_X2);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, NEG_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(neg_sum_rect_matrix_OK_1) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, NEG_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, NEG_SIMPLE_SEQUENCE_X2);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(neg_sum_rect_matrix_OK_2) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE_X2);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  matrix_filling(rows_REF, cols_REF, &test_matrix_REF, NEG_SIMPLE_SEQUENCE);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

/*===========================nill result tests============================*/

START_TEST(nill_sum_sqr_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 11;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 11;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 11;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  e_create_matrix(rows_REF, cols_REF, &test_matrix_REF);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

START_TEST(nill_sum_rect_matrix_OK) {
  // Arrange
  // matrix A
  int rows_A = 8;
  int cols_A = 11;
  matrix_t test_matrix_A = {0};
  matrix_filling(rows_A, cols_A, &test_matrix_A, POS_SIMPLE_SEQUENCE);
  // matrix B
  int rows_B = 8;
  int cols_B = 11;
  matrix_t test_matrix_B = {0};
  matrix_filling(rows_B, cols_B, &test_matrix_B, NEG_SIMPLE_SEQUENCE);
  // matrix sum_AB
  matrix_t test_matrix_SUM = {0};
  // matrix reference
  int rows_REF = 8;
  int cols_REF = 11;
  matrix_t test_matrix_REF = {0};
  e_create_matrix(rows_REF, cols_REF, &test_matrix_REF);

  // Act
  e_sum_matrix(&test_matrix_A, &test_matrix_B, &test_matrix_SUM);

  // Assert
  int match = e_eq_matrix(&test_matrix_SUM, &test_matrix_REF);
  ck_assert_int_eq(match, SUCCESS);

  e_remove_matrix(&test_matrix_A);
  e_remove_matrix(&test_matrix_B);
  e_remove_matrix(&test_matrix_SUM);
  e_remove_matrix(&test_matrix_REF);
}
END_TEST

Suite* sum_matrix(void) {
  Suite* s = suite_create("sum_matrix function suite");

  TCase* sum_matrix_errors =
      tcase_create("sum_matrix with errors function tests");
  tcase_add_test(sum_matrix_errors, sum_matrix_INCORRECT_MATRIX);
  tcase_add_test(sum_matrix_errors, sum_matrix_CALC_ERROR);
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
  printf("\033[0;31m\tFAILED: %d\n", failed);

  return failed ? 1 : 0;
}
