.PHONY: all lib e_matrix.a test gcov gcov_report style gost clean
# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
MAKE = make
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LEAKS = CK_FORK=no leaks --atExit --
	REPORT_OPEN = open
else ifeq ($(OS), Linux)
	LEAKS =
	REPORT_OPEN = xdg-open
endif

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address
ifeq ($(OS), Darwin)
	TEST_FLAGS = -lcheck
else ifeq ($(OS), Linux)
	TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FILENAMES
TARGET = e_matrix.a
TEST_EXE = e_matrix_test
SRC_DIR = ./src/
SRC = $(wildcard $(SRC_DIR)*.c)
OBJ_DIR = ./obj/
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
UNITS_DIR = ./units/
UNITS_SRC = $(wildcard $(UNITS_DIR)*.c)
TESTS_DIR = ./tests/
TESTS_SRC = $(wildcard $(TESTS_DIR)*.c)
GCOV_DATA_DIR = coverage_data/

all: clean e_matrix.a test gcov_report

# LIBRARY BUILDING
lib: clean $(TARGET)

$(TARGET): objects 
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ) OBJ_SUCCESS

makeobjdir:
	@$(MK) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CF) $(STD) -c $^ -o $@

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"

# TESTS
test: lib
	@$(CC) $(CF) $(GCOV_FLAGS) $(ASAN) $(TESTS_SRC) $(TARGET) -o $(TEST_EXE) $(TEST_FLAGS)
	$(LEAKS) ./$(TEST_EXE)

valgrind: lib
	@$(CC) $(CF) $(GCOV_FLAGS) $(TESTS_SRC) $(TARGET) -o $(TEST_EXE) $(TEST_FLAGS)
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(TEST_EXE)

docker_valgrind: clean
	cd ../materials/build/Valgrind/ && sh run.sh

# TEST COVERAGE
gcov: gcov_report

gcov_report: clean
	@$(CC) $(CF) $(TEST_FLAGS) $(GCOV_FLAGS) $(ASAN) $(TESTS_SRC) $(SRC) -o $(TEST_EXE)
	./$(TEST_EXE)
	@lcov -t "./gcov" -o report.info --no-external -c -d .
	@genhtml -o report report.info
	@gcovr -r . --html-details -o ./report/coverage_report.html
	@$(REPORT_OPEN) ./report/index.html
	@rm -rf *.gcno *.gcda gcov_test *.info

# SERVICE
style:
	clang-format --style=google -n e_matrix.h $(SRC) $(UNITS_SRC) $(TESTS_SRC)

gost:
	clang-format --style=google -i e_matrix.h $(SRC) $(UNITS_SRC) $(TESTS_SRC)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(TARGET)
	@rm -rf $(TEST_EXE)
	@rm -rf *.out *.dSYM ./tests/*.dSYM ./units/*dSYM
	@rm -rf *.gcno *.gcda ./report gcov_test *.info

# UNIT_TESTS
units: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_create: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_remove: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_eq: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_sum: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_sub: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_scalex: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_mult: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_transp: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_compl: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_det: lib
	$(MAKE) -C $(UNITS_DIR) $@
ut_inv: lib
	$(MAKE) -C $(UNITS_DIR) $@

man: lib
	@gcc $(ASAN) $(UNITS_DIR)man_tests.c $(TARGET)
#	@gcc $(ASAN) $(TEST_FLAGS) unit_tests.c $(TARGET) 
	@echo "\033[32m"
	@date +"%T"
	@echo "manual tests start\033[0m"
	@./a.out
	@rm -rf a.out *.dSYM
