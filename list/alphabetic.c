/*
** EPITECH PROJECT, 2018
** dmek
** File description:
** if a > b return 1
*/

#include "../list.h"

void    print_list(pieces_t *a)
{
	pieces_t	*tmp;

	tmp = a;
	while (tmp != NULL) {
		my_putstr(tmp->dir_name);
		my_putchar('\n');
		tmp = tmp->next;
	}
}

void    part_of_order_pieces(pieces_t *before, pieces_t *after,
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


int	alphabetic(char *a, char *b)
{
	int	i;

	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
		if (a[i] > b[i])
			return (1);
		if (a[i] < b[i])
			return (0);
	}
	if (b[i] == '\0')
		return (0);
	return (1);
}
