# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
MAKE = make

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
STD = -std=c11 -pedantic
ASAN = -g -fsanitize=address

# FILENAMES
TARGET = e_matrix.a
SRCDIR = ./src/
SRC = $(wildcard $(SRCDIR)*.c)
OBJDIR = ./obj/
OBJ = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
TESTDIR = ./tests/


# LIBRARY BUILDING
lib: clean $(TARGET)

$(TARGET): objects 
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ) OBJ_SUCCESS

makeobjdir:
	@$(MK) $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CF) -c $^ -o $@

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"

#TESTS
test: lib
	$(MAKE) -C $(TESTDIR) $@

ut_create:
	$(MAKE) -C $(TESTDIR) $@

ut_remove:
	$(MAKE) -C $(TESTDIR) $@

# SERVICE
style:
	clang-format --style=google -n e_matrix.h $(SRC) $(TESTDIR)*.c

gost:
	clang-format --style=google -i e_matrix.h $(SRC) $(TESTDIR)*.c

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TARGET)
	rm -rf *.out *.dSYM

man:
	@gcc $(ASAN) $(TESTDIR)man_tests.c $(TARGET)
	@echo "\033[32m"
	@date +"%T"
	@echo "manual tests start\033[0m"
	@./a.out
	@rm -rf a.out *.dSYM
