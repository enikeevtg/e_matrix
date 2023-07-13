# UTILITIES
CC = gcc
OPEN = open -e
LEAKS = CK_FORK=no leaks --atExit -- 
OS := $(shell uname)

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address
ifeq ($(OS), Darwin)
	TEST_FLAGS = -lcheck
else ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

# FILENAMES
LIB = ../e_matrix.a
TEST_TARGETS = create_matrix_test remove_matrix_test eq_matrix_test
TEST_TARGETS += sum_matrix_test sub_matrix_test
TEST_TARGETS += mult_number_test mult_matrix_test transpose_test
TEST_TARGETS += calc_complements_test determinant_test inverse_matrix_test

### log file
LOG = __test__e_matrix.log
# WRITELOG = >> $(LOG)
# OPENLOG = $(OPEN) $(LOG)

# UNIT-TESTS
units: clean UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\033[32m  >>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<" $(WRITELOG)
	@date +"          %dd-%mm-%yy %T"
	@echo "          (c) T.Enikeev\033[0m"

### create_matrix test
ut_create: clean create_matrix_test
	@$(OPENLOG)

create_matrix_test: create_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### remove_matrix test
ut_remove: clean remove_matrix_test
	@$(OPENLOG)

remove_matrix_test: remove_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### eq_matrix test
ut_eq: clean eq_matrix_test
	@$(OPENLOG)

eq_matrix_test: eq_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### sum_matrix test
ut_sum: clean sum_matrix_test
	@$(OPENLOG)

sum_matrix_test: sum_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### sub_matrix test
ut_sub: clean sub_matrix_test
	@$(OPENLOG)

sub_matrix_test: sub_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### mult_number test
ut_scalex: clean mult_number_test
	@$(OPENLOG)

mult_number_test: mult_number_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### mult_matrix test
ut_mult: clean mult_matrix_test
	@$(OPENLOG)

mult_matrix_test: mult_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### transpose test
ut_transp: clean transpose_test
	@$(OPENLOG)

transpose_test: transpose_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### calc_complemets test
ut_compl: clean calc_complements_test
	@$(OPENLOG)

calc_complements_test: calc_complements_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### determinant test
ut_det: clean determinant_test
	@$(OPENLOG)

determinant_test: determinant_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

### inverse_matrix test
ut_inv: clean inverse_matrix_test
	@$(OPENLOG)

inverse_matrix_test: inverse_matrix_test.c
	@echo "\n\033[0;33m$<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(STD) $(ASAN) $(TEST_FLAGS) $< $(LIB) -o $@
	@$(LEAKS)./$@ $(WRITELOG)
	@rm -f $@

# SERVICE
clean:
	@rm -rf $(LOG)
	@rm -rf *.dSYM
