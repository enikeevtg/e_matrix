#ifndef E_MATRIX_TESTS_TEST_H_
#define E_MATRIX_TESTS_TEST_H_

#include <check.h>
#include <limits.h>

#include "../e_matrix.h"

Suite* create_matrix();
Suite* remove_matrix();
Suite* eq_matrix();
Suite* sum_matrix();
Suite* sub_matrix();
Suite* mult_number();
Suite* mult_matrix();
Suite* transpose();
Suite* calc_complements();
Suite* determinant();
Suite* inverse_matrix();

#endif  // E_MATRIX_TESTS_TEST_H_
