##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	main.c				\
		main2.c				\
		main3.c				\
		help.c				\
		my_puts/my_puts.c		\
		list/linked_list.c		\
		list/alphabetic.c		\
		pieces/second_feed.c		\
		pieces/feed_pieces.c		\
		pieces/feed_pieces_error.c	\
		my_puts/put_in_array.c		\
		ncurse.c			\
		ncruse2.c			\
		ncurse3.c			\
		debug/debug.c			\
		debug/debug2.c			\
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
	rm -rf $(OBJ) $(NAME) *~ *#

re:	fclean all
