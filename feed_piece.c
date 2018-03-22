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
		if (buff[0] == '\n')
			read_files_next_line(&y, &i, &x, a);
	}
	a->map[y] = NULL;
}

int	errors(int y, char buff)
{
	if (y == 0 && (buff != ' '
		       && (buff < '0' || buff > '9')))
		return (0);
	if (y != 0 && buff != ' ' && buff != '*' && buff != '\n')
		return (0);
	return (1);
}

int	error_piece(char *file, pieces_t *a)
{
	int	fd;
	int	size;
	int	y = 0;
	char    buff[2];
	int	x[2] = {0,0};
	//printf("file:%s\n", file);
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
                return (0);
	for (size = read(fd, buff, 1); size > 0;
             size = read(fd, buff, 1)) {
		//	printf("buff:%c, x[0]:%d, x[1]:%d\n", buff[0], x[0], x[1]);
		if (buff[0] == '\n') {
			y++;
			if (x[1] < x[0] && y != 1)
				x[1] = x[0];
			x[0] = 0;
		}
		if (errors(y, buff[0]) == 0)
			return (0);
		x[0]++;
	}
	a->map = malloca(y, x[1]);
	close(fd);
	return (1);
}

int     feed_piece(pieces_t *a, char *name)
{
 	int     fd;
	int	size = 0;
 	char    *file;

	file = file_name(name, size);
	a->name = delete_after_point(name);
	if (error_piece(file, a) == 0) {
		a->size[0] = '0';
		a->size[1] = '0';
		a->map = NULL;
		return (0);
	}
        fd = open(file, O_RDONLY, 0644);//O_CREAT | O_RDWR | O_TRUNC, 0644);
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
		//printf("mem:%d,aav;%s\n", mem_x,av[y]);
		//mem_x = x;
		for (x = 0; av[y][x] != '\0'; x++);
		if (x > mem_x)
			mem_x = x;
	}
	//printf("x%d,y %d\n", mem_x, y);
	//printf("size0:%c, size1:%c\n", a->size[0], a->size[1]);
	if (y + '0' != a->size[1] || mem_x + '0' != a->size[0]) {
		printf("enter\n");
		a->size[1] = '0';
		a->size[0] = '0';
	}
	return (0);
}

void	feed_linked_list(pieces_t **a)
{
	pieces_t	*list = *a;
	char		*n;

	rand();
	while(list) {
		n = list->dir_name;
		feed_piece(list, n);
		list = list->next;
	}
	list = *a;
	while (list) {
		printf("list;%s\n", list->name);
		good_lines_and_rows_num(list, list->map);
		printf("iut:%c, %c\n\n\n\n", list->size[0], list->size[1]);
		list = list->next;
	}
}
