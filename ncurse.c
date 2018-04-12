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

	refresh();    
	ch = getch();
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
	printw("SCORE  : ");
	printw(de);
	printw("\n");
	printw("NEXT PIECE  :\n");
	print_map(c);
	free(de);
}


void	start_game_two(void)
{
	getchar();
	initscr();
	cbreak();
	timeout(50);
}

void	start_game_tree(char **av, char **reference, pieces_t *a, char score)
{
	start_color();
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	print_maps(av, reference, a->next->map, score);
}

void	start_game(debug_t *debug, pieces_t *a)
{
	char	**av;
	int	win = 0;
	char	**reference;
	int     clok = 0;
	char	score = '0';

	create_circular_list(a, &a);
	av = create_square(20, 20);
	reference = create_square(20, 20);
	start_game_two();
	while (win == 0) {
		if (clok + 2000 < clock())
			clok = clock();
		start_game_tree(av, reference, a, score);
		debug->ch = ncurse_stuff();
		if (clok  + 620 > clock())
			add_piece(av, reference, a, &a);
		gameplay(reference, av, a, debug);
		delete_complete_line(reference, av, &score);
	}
	endwin();
}
