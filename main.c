/*
** EPITECH PROJECT, 2018
** dke
** File description:
** dkmk
*/

//#include "list.h"
#include <stdlib.h>
//#include <stdio.h>                                               
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

int	main(int ac, char **av)
{
	pieces_t	*a = NULL;

	help(ac, av);
	a = get_pieces(a);
	order_pieces(&a, a);
	print_list(a);
	feed_linked_list(&a);
	free(a);
}
