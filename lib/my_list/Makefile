##
## EPITECH PROJECT, 2019
## Lib: list
## File description:
## Makefile of the list lib
##

NAME	=	libmy_list.a

all:	$(NAME)

$(NAME):
	cp my_list.h ../../include/
	gcc -c *.c -I../../include/ && ar rc $(NAME) *.o
	cp $(NAME) ../

clean:
	rm -f *.o

re:	clean all
