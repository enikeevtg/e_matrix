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

# SERVICE
style:
	clang-format --style=google -n *.h *.c $(SRC)

gost:
	clang-format --style=google -i *.h *.c $(SRC)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TARGET)
	rm *.out

man:
	@gcc man_tests.c src/*.c
	@./a.out
