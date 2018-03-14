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

int     alphabetic(char *a, char *b);

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

char	*file_name(char *name, int i)
{
	char	*file;
	char	*a = "tetriminos/";
	int	g;

	file = malloc(sizeof(char) * (my_strlen(name) + 11));
	for (i = 0; a[i] != '\0'; i++)
		file[i] = a[i];
	for (g = 0, i = i; name[g] != '\0'; g++, i++)
		file[i] = name[g];
	file[i] = '\0';
	return (file);	
}

int	feed_piece(int	i, pieces_t *a, char *name)
{
	int	fd;
	char	buff[2];
	int	size = 0;
//	char	*file;

	/*file =*/ file_name(name, size);
	//printf("%s\n", file);
	fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
//open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	for (size = read(fd, buff, 1); size > 0;
	     size = read(fd, buff, 1)) {
		//printf("%c\n", buff[0]);
		a->color = '1';
	}
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
		/*if (alphabetic(dir_name, tmp->next->dir_name) == 0) {
			printf("move\n");
			mv_from_there_all(tmp,a, dir_name);
			return (0);
			}*/
		tmp = tmp->next;
	}
	tmp->next = new;
	return (0);
}


int	get_pieces(void)
{
	DIR	*fd;
	struct dirent	*buff;
	pieces_t	*a = NULL;
	fd = opendir("tetriminos");
	for (buff = readdir(fd); buff != NULL; buff = readdir(fd)) {
		if (just_points(buff->d_name) != 0) {
			//printf("dir:%s\n", buff->d_name);
			place_dir_name_list(&a, a, buff->d_name);
		}
	}
	print_list(a);
	printf("--------\n");
	order_pieces(&a, a);
	closedir(fd);
	return (0);	
}

int	main(int ac, char **av)
{
	//pieces_t	*a = NULL;

	//a = malloc(sizeof(a));
	help(ac, av);
	get_pieces();
	//free(a);
}
