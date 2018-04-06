/*
** EPITECH PROJECT, 2018
** dm
** File description:
** dk
*/

#include "../list.h"

int	error_piece(char *file, pieces_t *a)
{
	int	fd;
	int	size;
	int	y = 0;
	char    buff[2];
	int	x[2] = {0,0};

	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		return (0);
	for (size = read(fd, buff, 1); size > 0;
	     size = read(fd, buff, 1)) {
		if (buff[0] == '\n')
			error_piece_next_line(&y, &x[1], &x[0]);
		if (errors(y, buff[0], &x[0]) == 0)
			return (0);
	}
	a->map = malloca(y, x[1]);
	close(fd);
	return (1);
}

int	before_error_piece(char *file, pieces_t *a)
{
	if (error_piece(file, a) == 0) {
		a->size[0] = '0';
		a->size[1] = '0';
		a->map = NULL;
		return (0);
	}
	return (1);
}

int     feed_piece(pieces_t *a, char *name)
{
	int     fd;
	int	size = 0;
	char    *file;

	file = file_name(name, size);
	a->name = delete_after_point(name);
	if (before_error_piece(file, a) == 0)
		return (0);
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1) {
		a->map = NULL;
		return (0);
	}
	read_files(fd, a);
	free(file);
	close(fd);
	return (1);
}

int	good_lines_and_rows_num(pieces_t *a, char **av)
{
	int	x = 0;
	int	y = 0;
	int	mem_x = 0;
	
	if (a->size[0] == '0' && a->size[1] == '0')
		return (0);
	for (y = 0; av[y] != NULL; y++) {
		for (x = 0; av[y][x] != '\0'; x++);
		if (x > mem_x)
			mem_x = x;
	}
	if (y + '0' != a->size[1] || mem_x + '0' != a->size[0]) {
		a->size[1] = '0';
		a->size[0] = '0';
	}
	return (0);
}

void	feed_linked_list(pieces_t **a)
{
	pieces_t	*list = *a;
	char		*n;

	while(list) {
		n = list->dir_name;
		feed_piece(list, n);
		list = list->next;
	}
	list = *a;
	while (list) {
		good_lines_and_rows_num(list, list->map);
		list = list->next;
	}
}
