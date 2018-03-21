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
#include <getopt.h>

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
	char	color;
	char	**map;
	char	size[2];
	char	*name;
}each;

typedef struct debug
{
	char	*left;
	char	*right;
	char	*turn;
	char	*drop;
	char	*quit;
	char	*pause;
	char	*next;
	char	*map_size;
	char	*level;
	char	*size;
}debug_t;
	
typedef struct	pieces
{
	char		color;
	char		**map;
	char		size[2];
	char		*name;
	char		*dir_name;
	struct pieces	*next;
}pieces_t;
void    start_game(void);
void    print_pieces_number(pieces_t *a);
void	print_debug(debug_t *a, debug_t *b);
int     debug_tetrimino(pieces_t *a);
void    print_array(char **map);
void    n_curing(pieces_t *a, debug_t *debub, debug_t *debug_text);

int     getopt_use(int ac, char **av, debug_t *debug);
void    print_debug(debug_t *a, debug_t *b);

int     alphabetic(char *a, char *b);
char    *file_name(char *name, int i);
int     feed_piece(pieces_t *a, char *name);
char	**malloca(int num_ar, int cha);
int **int_malloca(int num_ar, int cha);

int     my_strlen(char *av);
int	strcom(char *a, char *b);
char	**feed_empty(char **av);
char	**opene(char *av);
char	**insert_map(char *av, char **ptr);
char	**open_function(char	*av);
void    mv_from_there_all(pieces_t *list, pieces_t *a, char *dir_name);
int     help(int ac, char **av);
void    print_list(pieces_t *a);
void    order_pieces(pieces_t **list, pieces_t *a);
void    feed_linked_list(pieces_t **a);

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
