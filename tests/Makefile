# UTILITIES
CC = gcc
OPEN = open -e

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra #-g
TEST_FLAGS = -lcheck

# FILENAMES
LIB = ../e_matrix.a
TEST_TARGETS = create_matrix_test remove_matrix_test

### log file
LOG = __test__e_matrix.log
# WRITELOG = >> $(LOG)
# OPENLOG = $(OPEN) $(LOG)

# UNIT-TESTS
test: log_remove UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\033[32m  >>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<" $(WRITELOG)
	@date +"          %dd-%mm-%yy %T"
	@echo "          (c) T.Enikeev\033[0m"

### create_matrix test
ut_create: log_remove create_matrix_test

create_matrix_test: create_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< $(LIB) -o $@
	@./$@ $(WRITELOG)
	@$(OPENLOG)
	@rm -f $@

### remove_matrix test
ut_remove: log_remove remove_matrix_test

remove_matrix_test: remove_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< $(LIB) -o $@
	@./$@ $(WRITELOG)
	@$(OPENLOG)
	@rm -f $@


# SERVICE
log_remove:
	@rm -rf $(LOG)
