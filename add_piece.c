/*
** EPITECH PROJECT, 2018
** 
**  File description:
** by mrnsapple
*/

#include "list.h"

void	here_really_trans_map(pieces_t **b, int *i, char **reference)
{
	*b = (*b)->next;
	*i = 0;
	delete_all_stars(reference);
}

int	here_really_transform_map(char **av, char **reference,
				  pieces_t **b, int *i)
{
	int	y;
	int	x;

	for (y = 0; reference[y] != NULL; y++);
	for (y = y - 1; y != -1; y--)
		for (x = 0; reference[y][x] != '\0'; x++) {
			if (reference[y][x] == '_' &&
			    reference[y - 1][x] == '*') {
				here_really_trans_map(b, i, reference);
				return (0);
			}
			if (reference[y][x] == ' ' &&
			    reference[y - 1][x] == '*') {
				reference[y][x] = '*';
				reference[y - 1][x] = ' ';
				av[y][x] = '*';
				av[y - 1][x] = ' ';
			}
		}
	return (0);
}

int	number_stars(char **reference)
{
	int	i = 0;

	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 0; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*')
				i++;
	return (i);
}

void	i_is_0(char **av, char **reference, pieces_t **b, int *i)
{
	int	size;
	int	piece_stars;

	piece_stars = number_stars((*b)->map);
	piece_stars = piece_stars + '0';
	if (*i != 0) {
		size = *i + '0';
		if (size == piece_stars)
			here_really_transform_map(av, reference, b, i);
	}
}

void	add_piece(char **av, char **reference, pieces_t *a, pieces_t **b)
{
	int	i = 0;

	i = number_stars(reference);
	i_is_0(av, reference, b, &i);
	if (i == 0)
		for (int y = 0; (*b)->map[y] != NULL; y++)
			for (int x = 0; (*b)->map[y][x] != '\0'; x++) {
				if (av[y + 1][x + 1] == '*') {
					av = create_squaree(20, 20, reference);
					reference = create_squaree(20, 20,
								  reference);
					y = 0;
					x = 0;
				}
				av[y + 1][x + 1] = (*b)->map[y][x];
				reference[y + 1][x + 1] = (*b)->map[y][x];
			}
}
