##
## EPITECH PROJECT, 2019
## CPool_evalexpr_2019
## File description:
## Project makefile
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

CFLAGS	+= -Wall -Wextra -I./../include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L../lib/my -lmy

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
