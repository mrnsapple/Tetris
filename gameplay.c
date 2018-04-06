/*
* EPITECH PROJECT, 2018
** d
** File description:
** dk
*/

#include "list.h"
#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
 
void	can_move_right(char **reference, char **av, pieces_t *a)
{
	int	i = 0;
	int	left_stars = 0;

	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 1; reference[y][x] != '\0'; x++) {
			if (reference[y][x] == '*' &&
			    reference[y][x - 1] != '*')
				left_stars++;
		}
	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 1; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*' &&
			    (reference[y][x + 1] == ' '))
				i++;
	if (i == left_stars)
		move_right(reference, av);
}

void	move_left(char **reference, char **av)
{
	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 1; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*') {
				reference[y][x] = ' ';
				reference[y][x - 1] = '*';
				av[y][x] = ' ';
				av[y][x -1] = '*';
			}
}
 
void	can_move_left(char **reference, char **av, pieces_t *a)
{
	int	i = 0;
	int	left_stars = 0;

	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 1; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*' &&
			    reference[y][x + 1] != '*')
				left_stars++;
	for (int y = 0; reference[y] != NULL; y++)
		for (int x = 1; reference[y][x] != '\0'; x++)
			if (reference[y][x] == '*' &&
			    (reference[y][x - 1] == ' '))
				i++;
	if (i == left_stars)
		move_left(reference, av);
}

int	gameplay(int ch, char **reference, char **av, pieces_t *a)
{
	if (ch == KEY_RIGHT)
		can_move_right(reference, av, a);
	if (ch == KEY_LEFT)
		can_move_left(reference, av, a);
	if (ch == 27)
		endwin();
	return (0);
}
