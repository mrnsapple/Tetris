/*
** EPITECH PROJECT, 2018
** esoooo
** File description:
** eao
*/

#include "../list.h"

void	read_files_next_line(int *y, int *i, int *x, pieces_t *a)
{
	if (*y != -1)
		a->map[*y][*x - 1] = '\0';
	(*y)++;
	(*i)++;
	*x = 0;
}

void	read_files_two(int y, pieces_t *a)
{
	if (y == -1)
		exit(84);
	a->map[y] = NULL;
}

void	read_files_tree(int size, char buff, int *i, pieces_t *a)
{
	if (size == -1)
		exit(84);
	if (buff == ' ')
		(*i)++;
	if (((*i) == 0 || (*i) == 1) && buff != ' ')
		a->size[(*i)] = buff;
	if ((*i) == 2 && buff != ' ' && buff != '\n')
		a->color = buff;

}

void	read_files(int fd, pieces_t *a)
{
	int	size;
	int	i = 0;
	char	buff[1];
	int	y = -1;
	int	x = 0;

	for (size = read(fd, buff, 1); size > 0;
	     size = read(fd, buff, 1)) {
		read_files_tree(size, buff[0], &i, a);
		if (y != -1) {
			a->map[y][x] = buff[0];
			x++;
		}
		if (buff[0] == '\n')
			read_files_next_line(&y, &i, &x, a);
	}
	read_files_two(y, a);
}

int	errors(int y, char buff, int *x)
{
	(*x)++;
	if (y == 0 && (buff != ' '
		       && (buff < '0' || buff > '9')))
		return (0);
	if (y != 0 && buff != ' ' && buff != '*' && buff != '\n')
		return (0);
	return (1);
}
