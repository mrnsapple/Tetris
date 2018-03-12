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

int	get_pieces(pieces *a)
{
	DIR	*fd;
	struct dirent	*buff;
	int	i = 0;

	
	fd = opendir("tetriminos");
	for (buff = readdir(fd); buff != NULL; buff = readdir(fd))
		i++;
	a->piece = malloc(sizeof(each)* i + 1);
	printf("hehe%d\n", i);
	
	printf("hehe%d\n", i);
	initscr();
	start_color();
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(2));
	//printw("%s\n", buff->d_name);
	refresh();
	getch();
	clear();
	closedir(fd);
	endwin();
	return (0);	
}

int	main(int ac, char **av)
{
	pieces	*a;

	a = malloc(sizeof(a));
	help(ac, av);
	get_pieces(a);
	free(a);
}
