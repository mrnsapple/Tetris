/*
** EPITECH PROJECT, 2018
** de
** File description:
** dby oriol
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
	int	i;
	char	**av;

	av = malloca(20, 20);
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

char	**create_squaree(int y, int x, char **av)
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

void    create_circular_list(pieces_t *a, pieces_t **b)
{
	pieces_t	*c;
	int	     i = 0;

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
