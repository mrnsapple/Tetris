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
				av[i][g] = '!';
			else if (i == 0)
				av[i][g] = '^';
			else if(i == y - 1)
				av[i][g]  = '_';
			else
				av[i][g] = ' ';
			//if ((g == 0 && i == 0) || (g == x -1 && i == y - 1))
			//	av[i][g] = 'f';

		}
	}
	av[i] = NULL;
	return (av);
}

void	create_circular_list(pieces_t *a, pieces_t **b)
{
	pieces_t	*c;
	int		i = 0;
	while (a->next != NULL) {
		c = a;
		if (a->size[0] == '0' && a->size[1] == '0'
		    && i == 0)
			*b = a->next;
		else if(a->size[0] == '0' && a->size[1] == '0')
			c->next = a->next;
		a = a->next;
		i++;
	}
	a->next = (*b);
}

void	print_map(char **av)
{
	for (int i = 0; av[i] != NULL; i++) {
		printw(av[i]);
		printw("\n");
	}
}

int	ncurse_stuff(void)
{
	int	ch;

	refresh();    /* Print it on to the real screen */
	ch = getch();           /* Wait for user input */
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	clear();
	return (ch);
}

void	start_game(debug_t *debug, pieces_t *a)
{
	char	**av;
	int	win = 0;
	int	ch;
	char	**reference;
	//int     clock;/ = clock();
	//printf("i:%d\n", g);
	create_circular_list(a, &a);
	av = create_square(20, 20);
	reference = create_square(20, 20);
	getchar();
	initscr();
	while (win == 0) {
		start_color();
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		add_piece(av,reference, a, &a);
		print_map(av);
		print_map(reference);
		print_map(a->map);
		ch = ncurse_stuff();
		if (ch == 'r')
			win = 1;
		//a = a->next;
	}
	endwin();
}
