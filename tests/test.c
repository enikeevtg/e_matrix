#include "test.h"

int main(void) {
  int tests_count = 0;
  int failed = 0;

  Suite* matrix_tests[] = {
      create_matrix(),    remove_matrix(), eq_matrix(),      sum_matrix(),
      sub_matrix(),       mult_number(),   mult_matrix(),    transpose(),
      calc_complements(), determinant(),   inverse_matrix(), NULL};

  for (int i = 0; matrix_tests[i] != NULL; i++) {
    SRunner* runner = srunner_create(matrix_tests[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    printf("\n");
    srunner_run_all(runner, CK_NORMAL);
    tests_count += srunner_ntests_run(runner);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n");
  }
  printf("\033[0;32m\tSUCCESS: %d\n", tests_count - failed);
  printf("\033[0;31m\tFAILED: %d\n", failed);
  return failed ? 1 : 0;
}
