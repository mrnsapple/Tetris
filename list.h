/*
** EPITECH PROJECT, 2018
** djek
** File description:
** by oriol
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
#define PI		  -84

typedef struct	coord_t
{
	int	x;
	int	y;
	int	z;
} coord_t;

typedef	struct	each
{
	char	color;
	char	**map;
	char	size[2];
	char	*name;
} each;

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
	int	ch;
} debug_t;

typedef struct	pieces
{
	char		color;
	char		**map;
	char		size[2];
	char		*name;
	char		*dir_name;
	struct pieces	*next;
} pieces_t;

void			delete_all_stars(char **reference);
void			print_map(char **av);
int			 helped(int ac, char **av);
pieces_t		*order_pieces_two(pieces_t *after, pieces_t *tmp);
pieces_t		*get_pieces(pieces_t *a);
void	print_debug(debug_t *a, debug_t *b);
int	transform_debug_second(char *flag, int c,
				   int option_index, debug_t *debug);
void	move_right(char **reference, char **av);
int	just_points(char *a);
char	**create_squaree(int y, int x, char **av);
int	 after_slash_a_word(char **av);
void	n_curing(pieces_t *a, debug_t *debub, debug_t *debug_text);
char	**create_square(int y, int x);
void	create_circular_list(pieces_t *a, pieces_t **b);
void	error_piece_next_line(int *y, int *x_uno, int *x_dos);
char	**create_square(int y, int x);
void	delete_complete_line(char **av, char **reference, char *score);
int	 gameplay(char **reference, char **av, pieces_t *a, debug_t *debug);
void	add_piece(char **av, char **reference,pieces_t *a, pieces_t **b);
int	 number_stars(char **reference);
char	*file_name(char *name, int i);
char	*delete_after_point(char *name);
void	read_files_next_line(int *y, int *i, int *x, pieces_t *a);
void	read_files(int fd, pieces_t *a);
int	 errors(int y, char buff, int *x);
void	print_pieces_number(pieces_t *a);
void	print_debug(debug_t *a, debug_t *b);
int	 debug_tetrimino(pieces_t *a);
void	print_array(char **map);
void	n_curing(pieces_t *a, debug_t *debub, debug_t *debug_text);
void	start_game(debug_t *debug, pieces_t *a);
int	 getopt_use(int ac, char **av, debug_t *debug);
void	print_debug(debug_t *a, debug_t *b);
int	 alphabetic(char *a, char *b);
char	*file_name(char *name, int i);
int	 feed_piece(pieces_t *a, char *name);
char	**malloca(int num_ar, int cha);
int	**int_malloca(int num_ar, int cha);
void	print_map(char **av);
int	 my_strlen(char *av);
int	strcom(char *a, char *b);
char	**feed_empty(char **av);
char	**opene(char *av);
char	**insert_map(char *av, char **ptr);
char	**open_function(char *av);
void	mv_from_there_all(pieces_t *list, pieces_t *a, char *dir_name);
int	 help(int ac, char **av);
void	print_list(pieces_t *a);
void	order_pieces(pieces_t **list, pieces_t *a);
void	feed_linked_list(pieces_t **a);
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
