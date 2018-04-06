/*
** EPITECH PROJECT, 2018
** e
** File description:
** e
*/

#include "../list.h"

char    *file_name(char *name, int i)
{
	char    *file;
	char    *a = "tetriminos/";
	int     g;

	file = malloc(sizeof(char) * (my_strlen(name) + 25));
	for (i = 0; a[i] != '\0'; i++)
		file[i] = a[i];
	for (g = 0, i = i; name[g] != '\0'; g++, i++)
		file[i] = name[g];
	file[i] = '\0';
	return (file);
}

char	*delete_after_point(char *name)
{
	int     i;

	for (i = 0; name[i] != '\0'; i++);
	name[i - 10] = '\0';
	return (name);
}

void	read_files_next_line(int *y, int *i, int *x, pieces_t *a)
{
	if (*y != -1)
		a->map[*y][*x - 1] = '\0';
	(*y)++;
	(*i)++;
	*x = 0;
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
		if (buff[0] == ' ')
			i++;
		if ((i == 0 || i == 1) && buff[0] != ' ')
			a->size[i] = buff[0];
		if (i == 2 && buff[0] != ' ' && buff[0] != '\n')
			a->color = buff[0];
		if (y != -1) {
			a->map[y][x] = buff[0];
			x++;
		}
		if (buff[0] == '\n')
			read_files_next_line(&y, &i, &x, a);
	}
	if (y == -1)
		exit(84);
	a->map[y] = NULL;
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

