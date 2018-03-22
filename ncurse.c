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

char	**create_square(int y, int x, char **av)
{
	int	i;

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
	int	ch = 0;

	refresh();    /* Print it on to the real screen */
	ch = getch();           /* Wait for user input */
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	clear();
	return (ch);
}

void	print_maps(char **a, char **b, char **c, char score)
{
	char	*de;

	de = malloc(sizeof(char) * 3);
	de[0] = score;
	de[1] = '\0';
	print_map(a);
	print_map(b);
	
	printw("SCORE  : ");
	printw(de);
	printw("\n");
	printw("NEXT PIECE  :\n");
	print_map(c);
	free(de);
}
	
void	start_game(debug_t *debug, pieces_t *a)
{
	char	**av;
	int	win = 0;
	int	ch;
	char	**reference;
	int     clok;
	char	score = '0';
	
	printf("right:%d\n", KEY_RIGHT);
	create_circular_list(a, &a);
	av = malloca(20, 20);
	reference = malloca(20, 20);
	av = create_square(20, 20, av);
	reference = create_square(20, 20, reference);
	getchar();
	initscr();
	cbreak();         // don't interrupt for user input
	timeout(500);
	while (win == 0) {
		clok = clock();
		start_color();
		init_pair(2, COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR(2));
		add_piece(av,reference, a, &a);
		print_maps(av, reference, a->next->map, score);
		ch = ncurse_stuff();
		while(clok + 40000 > clock());
		gameplay(ch, reference, av, a);
		delete_complete_line(reference, av, &score);
	}
	endwin();
}
