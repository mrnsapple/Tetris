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
//	closedir(fd);
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
	while(a) {
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
			for (int y = 0; a->map != NULL &&  a->map[y] != NULL; y++) {
				my_putstr(a->map[y]);
				my_putchar('\n');
			}
		}
		a = a->next;
		
	}
	return (0);
}

debug_t	*initialize_debug(void)
{
	debug_t	*a;

	a = malloc(sizeof(debug_t));
	a->left = "left arrow";
        a->right = "right arrow";
        a->turn = "top";
        a->drop = "down arrow";
	a->quit = "q";
        a->pause = "space bar";
	a->next = "false";
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
//void	transform_debug
void	debug_mode(int ac, char **av, pieces_t *a)
{
	int	i;
	debug_t	*debug;
	debug_t	*debug_text;
	
	debug_text = initialize_debug_text();
	debug = initialize_debug();
	getopt_use(ac, av, debug);
	for (i = ac -1; i != 0; i--) {
	
		if (strcom("-D", av[i]) == 1) {
			my_putstr("*** DEBUG MODE ***");
			print_debug(debug_text, debug);
			my_putstr("\n");
			print_pieces_number(a);
			debug_tetrimino(a);
		}
	}
	free(debug);
	free(debug_text);
}

int	main(int ac, char **av)
{
	pieces_t	*a = NULL;

	for (int i = ac -1; i != 0; i--)
		if (strcom("--help", av[i]) == 1) {
			help(ac, av);
			return (0);
		}
	a = get_pieces(a);
	order_pieces(&a, a);
	//print_list(a);
	feed_linked_list(&a);
	debug_mode(ac, av, a);
	free(a);
	return (0);
}
