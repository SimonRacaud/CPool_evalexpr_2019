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
		operator_seeker.c	\
		make_operation.c

TEST	=	eval_expr.c             \
		parenthesis_seeker.c    \
		combine_operators.c     \
		operators.c             \
		compute.c               \
		my_putnbr_str.c		\
		operator_seeker.c	\
		make_operation.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test_combop:
	make -C ./lib/my
	gcc -W -Wall tests/test_combop.c $(TEST) --coverage -lcriterion -L./lib/my -lmy -I./include/ && ./a.out
	rm ./a.out

test_compute:
	make -C ./lib/my
	gcc -W -g -Wall tests/test_compute.c $(TEST) --coverage -lcriterion -L./lib/my -lmy -I./include/ && ./a.out
	rm ./a.out

test_parseek:
	make -C ./lib/my
	gcc -W -g -Wall tests/test_parseek.c $(TEST) --coverage -lcriterion -L./lib/my -lmy -I./include/ && ./a.out
	rm ./a.out

test_global:
	make -C ./lib/my
	gcc -W -g -Wall tests/test_global.c $(TEST) --coverage -lcriterion -L./lib/my -lmy -I./include/ && ./a.out
	rm ./a.out

test_oplen:
	make -C ./lib/my
	gcc -W -g -Wall tests/test_oplen.c $(TEST) --coverage -lcriterion -L./lib/my -lmy -I./include/ && ./a.out
	rm ./a.out
