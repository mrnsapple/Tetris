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

	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 0; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*')
				i = 1;
	printf("i:%d\n", i);
	if (i == 0) {
		for (int y = 0; a->map[y] != NULL; y++)
			for (int x = 0; a->map[y][x] != '\0'; x++) {
				av[y + 1][x + 1] = a->map[y][x];
				reference[y + 1][x + 1] = a->map[y][x];
			}
	}
	//print_map(av);
	
//its needed to add another piece
}
