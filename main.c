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
	if (getopt_use(ac, av, debug) == 0)
		return (NULL);
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
	if (debug == NULL)
		return (84);
	my_putstr("Press any key to start Tetris");
	start_game(debug, a);
	free(a);
	return (0);
}
