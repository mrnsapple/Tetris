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
#include <term.h>

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
	while (tmp->next)
		tmp = tmp->next;
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
	return (a);	
}

void	print_pieces_number(pieces_t *a)
{
	char	i;

	for (i = '0'; a != NULL; i++, a = a->next);
	my_putstr("Tetrimino :  ");
	my_putchar(i);
	my_putchar('\n');
}

int	debug_tetrimino(pieces_t *a)
{
	while (a) {
		my_putstr("Tetrimino :  Name ");
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

debug_t	*initialize_debug(void)
{
	debug_t	*a;

	a = malloc(sizeof(debug_t));
	a->left = "^EOD";
	a->right = "^EOC";
	a->turn = "^EOA";
	a->drop = "^EOB";
	a->quit = "q";
	a->pause = "(space)";
	a->next = "Yes";
	a->level = "1";
	a->size = "20*10";
	return (a);
}

debug_t	*initialize_debug_text(void)
{
	debug_t	*a;

	a = malloc(sizeof(debug_t));
	a->left = "\nKey Left :  ";
	a->right = "\nKey Right :  ";
	a->turn = "\nKey Turn :  "; 
	a->drop = "\nKey Drop :  "; 
	a->quit = "\nKey Quit :  "; 
	a->pause = "\nKey Pause :  ";
	a->next = "\nNext :  "; 
	a->level = "\nLevel :  ";
	a->size = "\nSize :  ";
	return (a);
}

debug_t	*debug_mode(int ac, char **av, pieces_t *a)
{
	int	i;
	debug_t	*debug;
	debug_t	*debug_text;

	debug_text = initialize_debug_text();
	debug = initialize_debug();
	getopt_use(ac, av, debug);
	for (i = ac -1; i != 0; i--)
		if (strcom("-D", av[i]) == 1)
			n_curing(a, debug, debug_text);
	free(debug_text);
	return (debug);
}

int	main(int ac, char **av)
{
	pieces_t	*a = NULL;
	debug_t		*debug = NULL;

	for (int i = ac -1; i != 0; i--)
		if (strcom("--help", av[i]) == 1) {
			help(ac, av);
			return (0);
		}
	a = get_pieces(a);
	if (a == NULL)
		return (84);
	order_pieces(&a, a);
	feed_linked_list(&a);
	debug = debug_mode(ac, av, a);
	my_putstr("Press any key to start Tetris");
	start_game(debug, a);
	free(a);
	return (0);
}
