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

char	**create_square(int y, int x)
{
	char	**av;
	int	i;

	av = malloca(y, x);
	for (i = 0; i != y; i++) {
		for (int g = 0; g != x; g++) {
			if (g == 0 || g == x - 1)
				av[i][g] = '|';
			else if (i == 0)
				av[i][g] = '-';
			else if(i == y - 1)
				av[i][g]  = '_';
			else
				av[i][g] = ' ';
			if ((g == 0 && i == 0) || (g == x -1 && i == y - 1))
				av[i][g] = 'f';

		}
	}
	av[i] = NULL;
	return (av);
}

void	start_game(void)//should have a, debug and debug_text
{
	char	**av;
	
	av = create_square(20, 20);
	getchar();
	initscr();
	//my_putstr(av[0]);
	for (int i = 0; av[i] != NULL; i++) {
		printw(av[i]);
		printw("\n");
	}
	refresh();    /* Print it on to the real screen */
	getch();           /* Wait for user input */
	endwin();
	noecho();
	keypad(stdscr, TRUE);
	//return (0);
}
