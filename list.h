/*
** EPITECH PROJECT, 2018
** djek
** File description:
** dekde
*/

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

#ifndef LIST_H_
#define LIST_H_
#define PI	      -84

typedef struct	coord_t
{
	int	x;
	int	y;
	int	z;
}coord_t;

typedef	struct	each
{
	int	color;
	char	**map;
	char	size[2];
	char	*name;
}each;

typedef struct	pieces_t
{
	struct	each *piece;
}pieces;

int	strcom(char *a, char *b);
char	**feed_empty(char **av);
char	**opene(char *av);
char	**insert_map(char *av, char **ptr);
char	**open_function(char	*av);
int     help(int ac, char **av);

int	my_strcmp(char *pwd, char *line);
int	my_put_nbr(int nb);
char	*get_next_line(int fd);
int	my_get_nbr(char *str);
int	my_putstr_error(char *str);
int	**big_2(int lines_with, int **game, int num_match, int lines);
char	**malloca(int num_ar, int cha);
int	**int_malloca(int num_ar, int cha);
void	error(int ac);
void	my_putchar(char c);
int	my_putstr(char *str);

#endif
