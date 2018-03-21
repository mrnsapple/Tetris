/*
** EPITECH PROJECT, 2018
** dk
** File description:
** dj
*/

#include "list.h"

void	add_piece(char **av, char **reference,pieces_t *a)
{
	int	i = 0;

	for (int y = 0; av[y] != NULL; y++)
		for (int x = 0; av[y][x] != '\0'; x++)
			if (av[y][x] == '*')
				i = 1;
	printf("i:%d\n", i);
	//if (i == 0)//its needed to add another piece
}
