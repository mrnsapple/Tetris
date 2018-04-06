/*
** EPITECH PROJECT, 2018
** dk
** File description:
** del
*/

#include "../list.h"

void	print_list(pieces_t *a)
{
	pieces_t	*tmp;

	tmp = a;
	while (tmp != NULL) {
		my_putstr(tmp->dir_name);
		my_putchar('\n');
		tmp = tmp->next;
	}
}

void	part_of_order_pieces(pieces_t *before, pieces_t *after,
			     pieces_t *a, pieces_t *tmp)
{
	pieces_t	**list = &a;

	a = after;
	*list = a;
	tmp = *list;
}

pieces_t	*order_pieces_two(pieces_t *after, pieces_t *tmp)
{
	after = tmp->next;
	if (tmp->next->next == NULL)
		tmp->next = NULL;
	else
		tmp->next = tmp->next->next;
	after->next = tmp;
	return (after);
}

void	order_pieces_rotate(pieces_t *a, pieces_t *after,
			    pieces_t **list, pieces_t *tmp)
{
	a = after;
	*list = a;
	tmp = *list;
}

int	before_is_tmp(pieces_t *before, pieces_t *tmp)
{
	before = tmp;
	return (-1);
}

void	order_pieces_else(pieces_t **before, pieces_t **tmp)
{
	*before = *tmp;
	*tmp = (*tmp)->next;
}

void	order_pieces_else2(pieces_t **b, pieces_t *after,
			   pieces_t **list, pieces_t *a)
{
	*b = after;
	*list = a;
}

void	order_pieces(pieces_t **list, pieces_t *a)
{
	pieces_t	*tmp;
	pieces_t	*after = NULL;
	pieces_t	*b = NULL;
	pieces_t	*before = NULL;
	
	tmp = *list;
	for (int i = 0; tmp->next; i++) {
		if (alphabetic(tmp->dir_name, tmp->next->dir_name) != 0) {
			after = order_pieces_two(after, tmp);
			if (before == NULL || i == 0)
				order_pieces_rotate(a, after, list, tmp);
			else {
				order_pieces_else2(&b, after, list, a);
				tmp = *list;
				before->next = b;
			}
			i = before_is_tmp(before, tmp);
		} else
			order_pieces_else(&before, &tmp);
	}
}
