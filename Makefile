# UTILITIES
CC = gcc
AR = ar rs

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra

# FILENAMES
TARGET = e_matrix.a

SRCDIR = ./src/
SRC = $(wildcard $(SRCDIR)*.c)

OBJDIR = ./obj/
OBJ = $(putsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))

TESTDIR = ./tests/

# SERVICE
style:
	clang-format --style=google -n e_matrix.h $(SRC) $(TESTDIR)*.c

gost:
	clang-format --style=google -i e_matrix.h $(SRC) $(TESTDIR)*.c


clean:
	rm -rf $(OBJDIR)
	rm -rf $(TARGET)
	rm *.out

man:
	@gcc -g $(TESTDIR)man_tests.c $(SRC)
	@./a.out
#	@rm a.out
