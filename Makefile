##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## my_makefile
##


SRC	=	src/mini_printf.c	\
		src/putnbr.c	\
		src/my_putstr.c	\
		src/nbrlen.c	\
		src/my_strcmp.c	\
		src/my_strdup.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/str_to_word_array.c	\
		src/usage.c	\
		main.c	\
		src/form_str_int.c	\
		src/handle_error.c	\
		src/create_map.c	\
		src/my_str_isnum.c	\
		src/display_map.c \
		src/connection.c	\
		src/file_manipulations.c	\
		src/signaler.c	\
		src/attacking_function.c	\
		src/error_checker.c
OBJ	=	$(SRC:.c=.o)

NAME	=	my_navy

UNIT_TEST = unit_test

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc  $(SRC) -o $(NAME) -g3

clean :
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~
	rm -f *.vgcore
	rm -f $(UNIT_TEST)
	rm -f *vgcore.*

fclean: clean
	rm -f coding-style-reports.log
	rm -f $(NAME)

re:	fclean all

code: fclean
	clear
	coding-style . .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

unit_tests:	fclean
	gcc -o $(UNIT_TEST) \
	src/my_strdup.c src/my_strlen.c \
	src/my_putchar.c \
	src/my_putstr.c tests/unitest.c \
	--coverage -lcriterion -lgcov -lm

tests_run:	unit_tests
		./$(UNIT_TEST)
		gcovr  --exclude tests/ --branches
