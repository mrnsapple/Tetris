/*
** EPITECH PROJECT, 2018
** dke
** File description:
** dkmk
*/

#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "list.h"

int     strcom(char *a, char *b)
{
        int     i;
	
        for (i = 0; a[i] != '\0'; i++)
	        if (a[i] != b[i])
                        return (0);
        if (b[i] != '\0')
	        return (0);
        return (1);
}

int	just_points(char *a)
{
	int	i;
	int	g = 0;
	
	for (i = 0; a[i] != '\0'; i++)
		if (a[i] != '.')
			g++;
	return (g);
}
		
int	place_dir_name_list(pieces_t **list, pieces_t *a, char *dir_name)
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
	while(tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = new;
	return (0);
}


pieces_t	*get_pieces(pieces_t *a)
{
	DIR	*fd;
	struct dirent	*buff;

	fd = opendir("tetriminos");
	for (buff = readdir(fd); buff != NULL; buff = readdir(fd)) {
		if (just_points(buff->d_name) != 0) {
			place_dir_name_list(&a, a, buff->d_name);
		}
	}
	closedir(fd);
	return (a);	
}

int	debug_tetrimino(pieces_t *a)
{
	
	while(a) {
		my_putstr("Tetrimino :  Name ");
		my_putstr(a->name);
		if (a->size[0] == '0' && a->size[1] == '0') {
			my_putstr(" :  Error\n");
		}
		else {
			my_putstr(" :  Size ");
			my_putchar(a->size[0]);
			my_putchar('*');
			my_putchar(a->size[1]);
			my_putstr(" :  Color ");
			my_putchar(a->color);
			my_putstr(" :\n");
			for (int y = 0; a->map != NULL &&  a->map[y] != NULL; y++) {
				my_putstr(a->map[y]);
				my_putchar('\n');
			}
		}
		a = a->next;
		
	}
	return (0);
}

void	debug_mode(int ac, char **av, pieces_t *a)
{
	int	i;
	debug_t	*debug;

	debug = malloc(sizeof(debug_t));
	for (i = ac -1; i != 0; i--)
		if (strcom("-D", av[i]) == 1) {
			my_putstr("*** DEBUG MODE ***");
			my_putstr("\nKey Left :  ");
			my_putstr("\nKey Right :  ");
			my_putstr("\nKey Turn :  ");
			my_putstr("\nKey Drop :  ");
			my_putstr("\nKey Quit :  ");
			my_putstr("\nKey Pause :  ");
			my_putstr("\nNext :  ");
			my_putstr("\nLevel :  ");
			my_putstr("\nSize :  ");
			my_putstr("\n");
			debug_tetrimino(a);
		}
	free(debug);
}

int	main(int ac, char **av)
{
	pieces_t	*a = NULL;

	help(ac, av);
	a = get_pieces(a);
	order_pieces(&a, a);
	print_list(a);
	feed_linked_list(&a);
	debug_mode(ac, av, a);
	free(a);
}
