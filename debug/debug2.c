/*
** EPITECH PROJECT, 2018
** dkwnmwkand
** File description:
** by mrnsapple
*/

#include "../list.h"

void	print_debug(debug_t *a, debug_t *b)
{
	my_putstr(a->left);
	my_putstr(b->left);
	my_putstr(a->right);
	my_putstr(b->right);
	my_putstr(a->turn);
	my_putstr(b->turn);
	my_putstr(a->drop);
	my_putstr(b->drop);
	my_putstr(a->quit);
	my_putstr(b->quit);
	my_putstr(a->pause);
	my_putstr(b->pause);
	my_putstr(a->next);
	my_putstr(b->next);
	my_putstr(a->level);
	my_putstr(b->level);
	my_putstr(a->size);
	my_putstr(b->size);
}

int	what_word_is(char *av)
{
	int	i;
	
	i = my_strlen(av);
	if (i == 1)
		return (1);
	else if (i == 0)
		return (0);
	else
		if (my_strcmp("(space)", av) == 1)
			return (1);
	return (0);	
}

int	after_slash_a_word(char **av)
{
	for (int i = 0; av[i] != NULL; i++) {
		if (my_strcmp("-", av[i]) == 1)
			return (0);
		if (my_strcmp("-D", av[i]) == 1 && av[i + 1] != NULL &&
		    av[i + 1][0] != '-')
			return (0);
		if (my_strlen(av[i]) >= 2 && av[i + 1] != NULL &&
		    my_strcmp("-D", av[i]) != 1)
			if (av[i][0] == '-' && av[i][1] != '-') {
				if (av[i + 1][0] == '-')
					return (0);
				if  (what_word_is(av[i + 1]) != 1)
					return (0);
			}
	}
	return (1);
}

int	transform_debug_second(char *flag, int c,
			       int option_index, debug_t *debug) {
	if (c == 'l')
		debug->left = flag;
	else if (c == 'r')
		debug->right = flag;
	else if (c == 't')
		debug->turn = flag;
	else if (c == 'd')
		debug->drop = flag;
	else if (c == 'q')
		debug->quit = flag;
	else if (c == 'p')
		debug->pause = flag;
	else if (c == 'w')
		debug->next = flag;
	else if (c == 'm')
		debug->map_size = flag;
	else
		return (0);
	return (1);
}
