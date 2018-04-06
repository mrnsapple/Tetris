/*
** EPITECH PROJECT, 2018
** demdek
** File description:
** demkdek
*/

#include "list.h"

int	strcom(char *a, char *b)
{
	int     i;

	for (i = 0; a[i] != '\0'; i = i + 1) {
		if (a[i] != b[i])
			return (0);
	}
	if (b[i] != '\0')
		return (0);
	return (1);
}

int	just_points(char *a)
{
	int     i;
	int     g = 0;
	
	for (i = 0; a[i] != '\0'; i++)
		if (a[i] != '.')
			g++;
	return (g);
}

void	move_right(char **reference, char **av)
{
	int     l;

	for (l = 0; reference[0][l] != '\0'; l++);
	for (int y = 0; reference[y] != NULL; y++)
		for (int x = l - 1; x != 0; x--) {
			if (reference[y][x] == '*') {
				reference[y][x] = ' ';
				reference[y][x + 1] = '*';
				av[y][x] = ' ';
				av[y][x + 1] = '*';
			}
		}
}

