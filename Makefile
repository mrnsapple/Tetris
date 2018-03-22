##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	main.c				\
		help.c				\
		my_puts/my_puts.c		\
		my_puts/my_put_nbr.c		\
		list/linked_list.c		\
		list/alphabetic.c		\
		pieces/second_feed.c		\
		pieces/feed_pieces.c		\
		my_puts/put_in_array.c		\
		ncurse.c			\
		debug.c				\
		add_piece.c			\
		gameplay.c			\
		delete_line.c

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
