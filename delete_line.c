/*
** EPITECH PROJECT, 2018
** dj
** File description:
** dk
*/

#include "list.h"

void	delete_line(char **a, int y)
{
	for (y = y; y != 1; y--)
		for (int x = 0; a[y][x] != '\0'; x++)
			a[y][x] = a[y - 1][x];
}

void	delete_complete_line(char **av, char **reference, char *score)
{
	int	l;
	int	stars = 0;

	for (l = 0; reference[0][l] != '\0'; l++);
	for (int y = 0; reference[y] != NULL; y++) {
		stars = 0;
                for (int x = 0; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*')
				stars++;
		if (stars == l - 7) {
			(*score)++;
			delete_line(reference, y);
			delete_line(av, y);
			y = 0;
		}
}
}
