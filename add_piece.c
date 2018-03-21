/*
** EPITECH PROJECT, 2018
** dk
** File description:
** dj
*/

#include "list.h"

int	move_piece(char **av, char **reference)
{
	int	i = 0;
	int	g = -1;
	int	x;
	
	for (int y = 0; reference[y + 1] != NULL; y++, g = -1) {
		for (x = 0; reference[y][x] != '\0'; x++) {
			if (reference[y][x] == '*')
				i = 1;
			if (reference[y + 1][x] == '*')
				g = 0;
		}
		if (i == 1 && g == -1) {
			printw("hehe");
			printw(reference[y - 1]);
			printw("hehe");
			printw(reference[y]);
			printw("\n");
			return (0);
		}
	}
	return (0);
}

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
	else
		move_piece(av, reference);
	
		
	//print_map(av);
	
//its needed to add another piece
}
