/*
** EPITECH PROJECT, 2018
** dk Aimane
** File description:
** dj Oriol
*/

#include "list.h"

void	delete_all_stars(char **reference)
{
	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 0; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*')
				reference[y][x] = '_';
}

int	here_really_transform_map(char **av, char **reference, pieces_t **b, int *i)
{
	int	y;
	int	x;

	for (y = 0; reference[y] != NULL; y++);
	for (y = y - 1; y != -1; y--) {
		for (x = 0; reference[y][x] != '\0'; x++) {
			if (reference[y][x] == '_' && reference[y - 1][x] == '*') {
				*b = (*b)->next;
				printw("stardelete\n");
				*i = 0;
				delete_all_stars(reference);
				return (0);
			}
			if (reference[y][x] == ' ' && reference[y - 1][x] == '*') {
				reference[y][x] = '*';
				reference[y - 1][x] = ' ';
				av[y][x] = '*';
				av[y - 1][x] = ' ';
			}
		}
	}
	return (0);
}
       
/*int	move_piece(char **reference)
{
	int	x;
	int	y = 0;
	char	size = '0';

	for (y = 0; reference[y] != NULL; y++)
		for (x = 0; reference[y][x] != '\0'; x++) {
			if ((reference[y][x] == ' ' || reference[y][x] == '_')
			     && reference[y - 1][x] == '*')
				size = size + 1;
		}
	return (size);
}*/

int	number_stars(char **reference)
{
	int	i = 0;

	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 0; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*')
				i++;
	return (i);
}

void	add_piece(char **av, char **reference, pieces_t *a, pieces_t **b)
{
	int	i = 0;
	int	size;
	char	*de;
	int	piece_stars;

	printw("name\n");
	printw(a->name);
	de = malloc(sizeof(char) * 3);
	i = number_stars(reference);
	piece_stars = number_stars((*b)->map);
	piece_stars = piece_stars + '0';
	if (i != 0) {
		//size = move_piece(reference);
		size = i + '0';
		de[0] = size;
		de[1] = '\0';
		printw("size:");
		printw(de);
		printw("\n");
		printw("sizea:");
		de[0] = piece_stars;
		de[1] = '\0';
		printw(de);
		printw("\n");
		if (size == piece_stars)
			here_really_transform_map(av, reference, b, &i);
	}
	if (i == 0) {
		for (int y = 0; (*b)->map[y] != NULL; y++)
			for (int x = 0; (*b)->map[y][x] != '\0'; x++) {
				av[y + 1][x + 1] = (*b)->map[y][x];
				reference[y + 1][x + 1] = (*b)->map[y][x];
			}
	}
}
