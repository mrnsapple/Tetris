/*
** EPITECH PROJECT, 2018
** dj
** File description:
** dk
*/


#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "list.h"

void	n_curing(pieces_t *a, debug_t *debub, debug_t *debug_text)
{
	
	my_putstr("*** DEBUG MODE ***");
	print_debug(debug_text, debub);
	my_putstr("\n");
	print_pieces_number(a);
	debug_tetrimino(a);
}

//void	create_square(int i, int g)
void	start_game(void)//should have a, debug and debug_text
{
//	char	*av;

//	av = malloca(20, 10);
//	av = create_square(20, 10);
	getchar();
	initscr();      /* Start curses mode*/
	printw("ndasnsn;an\n");
        refresh();     /* Print it on to the real screen */
	getch();           /* Wait for user input */
	printf("huuufu\n");
	endwin();
	noecho();
	keypad(stdscr, TRUE);
	//return (0);
}
