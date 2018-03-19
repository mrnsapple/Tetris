##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	main.c			\
		help.c			\
		my_puts.c		\
		my_put_nbr.c		\
		linked_list.c		\
		alphabetic.c		\
		feed_piece.c		\
		put_in_array.c		\
		debug.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	tetris

RM	=	rm -f

all:	$(NAME)


$(NAME):	$(OBJ)
	gcc -g -Wall -Werror -o $(NAME) $(SRC) -lncurses

clean:
	$(RM) $(NAME)

fclean:	clean
	rm -f $(OBJ) $(NAME) *~ *#

re:	fclean all
