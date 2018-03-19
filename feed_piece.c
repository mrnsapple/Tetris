/*
** EPITECH PROJECT, 2018
** dm
** File description:
** dk
*/

#include "list.h"

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
	int	i;
	
	for (i = 0; name[i] != '\0'; i++);
	name[i - 10] = '\0';
	return (name);
}

void	read_files(int fd, pieces_t *a)
{
	int	size;
	int	i = 0;
	char    buff[1];
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
		if (buff[0] == '\n') {
			if (y != -1)
				a->map[y][x - 1] = '\0';
			y++;
			i++;
			x = 0;
		}
	}
	a->map[y] = NULL;
}

int	error_piece(char *file, pieces_t *a)
{
	int	fd;
	int	size;
	int	y = 0;
	char    buff[1];
	int	x[2] = {0,0};

	fd = open(file, O_RDONLY);
	if (fd == -1)
                return (0);
	for (size = read(fd, buff, 1); size > 0;
             size = read(fd, buff, 1)) {
		if (buff[0] == '\n') {
			y++;
			if (x[1] < x[0] && y != 1)
				x[1] = x[0];
			x[0] = 0;
		}
		if (y == 0 && (buff[0] != ' '
			       && (buff[0] < '0' || buff[0] > '9')))
			return (0);
		if (y != 0 && buff[0] != ' ' && buff[0] != '*'
		    && buff[0] != '\n')
			return (0);
		x[0]++;
	}
	a->map = malloca(y, x[1]);
	return (1);
}

int     feed_piece(pieces_t *a, char *name)
{
 	int     fd;
	int	size = 0;
 	char    *file;

//	my_putstr(name);

	file = file_name(name, size);
	a->name = delete_after_point(name);
	if (error_piece(file, a) == 0) {
		a->size[0] = '0';
		a->size[1] = '0';
		a->map = NULL;
		return (0);
	}
        fd = open(file, O_RDONLY);//O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (fd == -1) {
		a->map = NULL;
                return (0);
	}
	read_files(fd, a);
	return (1);
}

void	feed_linked_list(pieces_t **a)
{
	pieces_t	*list = *a;
	char		*n;
	printf(" ");
	while(list) {
		n = list->dir_name;
		feed_piece(list, n);
		list = list->next;
	}
}
