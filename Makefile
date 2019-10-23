##
## EPITECH PROJECT, 2019
## CPool_evalexpr_2019
## File description:
## Project makefile
##

SRC	=	main.c			\
		eval_expr.c		\
		parenthesis_seeker.c	\
		combine_operators.c	\
		operators.c		\
		compute.c		\
		my_putnbr_str.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test_combop:
	gcc -W -Wall tests/test_combop.c combine_operators.c --coverage -lcriterion -o test.out -L./lib/my -lmy -I./include/ && ./test.out
	rm ./test.out
	rm -f *.gcda
	rm -f *.gcno

test_compute:
	gcc -W -g -Wall tests/test_compute.c my_putnbr_str.c compute.c operators.c --coverage -lcriterion -o test.out -L./lib/my -lmy -I./include/ && ./test.out
	rm ./test.out
	rm -f *.gcda
	rm -f *.gcno
