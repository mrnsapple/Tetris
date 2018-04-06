/*
** EPITECH PROJECT, 2018
** dkwnmwkand
** File description:
** dekad
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

void	transform_debug_second(char *flag, int c,
			       int option_index, debug_t *debug) {
	if (c == 'l')
		debug->left = flag;
	if (c == 'r')
		debug->right = flag;
	if (c == 't')
		debug->turn = flag;
	if (c == 'd')
		debug->drop = flag;
	if (c == 'q')
		debug->quit = flag;
	if (c == 'p')
		debug->pause = flag;
	if (c == 'w')
		debug->next = flag;
	if (c == 'm')
		debug->map_size = flag;
}
