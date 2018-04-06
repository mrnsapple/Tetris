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

void	order_pieces(pieces_t **list, pieces_t *a)
{
	pieces_t	*tmp;
	pieces_t	*after;
	pieces_t	*b;
	pieces_t	*before = NULL;
	int		i = 0;

	tmp = *list;
	while (tmp->next) {
		if (alphabetic(tmp->dir_name, tmp->next->dir_name) != 0) {
			after = tmp->next;
			if (tmp->next->next == NULL)
				tmp->next = NULL;
			else
				tmp->next = tmp->next->next;
			after->next = tmp;
			if (before == NULL || i == 0) {
				a = after;
				*list = a;
				tmp = *list;
			}
			else {
				b = after;
				*list = a;
				tmp = *list;
				before->next = b;
			}
			before = tmp;
			i = -1;
		}
		else {
			before = tmp;
			tmp = tmp->next;
		}
		i++;
	}
}
