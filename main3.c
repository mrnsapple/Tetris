/*
** EPITECH PROJECT, 2018
** deke
** File description:
** deoif
*/

#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "list.h"
#include <term.h>

int     place_dir_name_list(pieces_t **list, pieces_t *a, char *dir_name)
{
	pieces_t	*tmp;
	pieces_t	*new;

	new = malloc(sizeof(pieces_t));
	new->dir_name = dir_name;
	new->next = NULL;;
	tmp = (*list);
	if (*list == NULL) {
		*list = new;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

pieces_t	*get_pieces(pieces_t *a)
{
	DIR		*fd;
	struct dirent	*buff;

	fd = opendir("tetriminos");
	if (fd == NULL)
		return (NULL);
	for (buff = readdir(fd); buff != NULL; buff = readdir(fd)) {
		if (just_points(buff->d_name) != 0) {
			place_dir_name_list(&a, a, buff->d_name);
		}
	}
	return (a);
}

void	print_pieces_number(pieces_t *a)
{
	char	i;

	for (i = '0'; a != NULL; i++, a = a->next);
	my_putstr("Tetriminos :  ");
	my_putchar(i);
	my_putchar('\n');
}

int	debug_tetrimino(pieces_t *a)
{
 	while (a) {
		my_putstr("Tetriminos :  Name ");
		my_putstr(a->name);
		if (a->size[0] == '0' && a->size[1] == '0')
			my_putstr(" :  Error\n");
		else {
			my_putstr(" :  Size ");
			my_putchar(a->size[0]);
			my_putchar('*');
			my_putchar(a->size[1]);
			my_putstr(" :  Color ");
			my_putchar(a->color);
			my_putstr(" :\n");
			print_array(a->map);
		}
		a = a->next;
	}
	return (0);
}

