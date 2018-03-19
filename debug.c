/*
** EPITECH PROJECT, 2018
** dkd
** File description:
** dk
*/

#include "list.h"

void	print_debug(debug_t *a, debug_t *b)
{
	my_putstr(a->left);
	my_putstr(b->left);
	my_putstr(a->right);
	my_putstr(b->right);
	my_putstr(a->turn);
	my_putstr(b->turn);
	my_putstr(a->drop);
	my_putstr(b->drop);
	my_putstr(a->quit);
	my_putstr(b->quit);
	my_putstr(a->pause);
	my_putstr(b->pause);
	my_putstr(a->next);
	my_putstr(b->next);
	my_putstr(a->level);
	my_putstr(b->level);
	my_putstr(a->size);
	my_putstr(b->size);
}

void	transform_debug_second(char *flag, int c,int option_index, debug_t *debug) {
	if (c == 'q')
		debug->quit = flag;
	if (c == 'p')
		debug->pause = flag;
	if (c == 'w')
		debug->next = flag;
	if (c == 'm')
		debug->map_size = flag;
	
}

int	transform_debug(int c,int option_index, debug_t *debug)
{
	
	char	*flag = NULL;

	flag = optarg;
	if (flag == NULL)
		return (0);
	if (c == 'L')
		debug->level = flag;
	if (c == 'l')
		debug->left = flag;
	if (c == 'r')
		debug->right = flag;
	if (c == 't')
		debug->turn = flag;
	if (c == 'd')
		debug->drop = flag;
	transform_debug_second(flag, c ,option_index, debug);
	printf("filename:%s\n", flag);
	return (0);
}

int	getopt_use(int ac, char **av, debug_t *debug)
{
	//int	i;
	int	option_index = 0;
	int	c;	

	static struct option long_options[] =
		{
			{"level", required_argument, 0, 'L'},
			{"key-left", required_argument, 0, 'l'},
			{"key-right", required_argument, 0, 'r'},
			{"key-turn", required_argument, 0, 't'},
			{"key-drop", required_argument, 0, 'd'},
			{"key-quit", required_argument, 0, 'q'},
			{"key-pause", required_argument, 0, 'p'},
			{"withour-next", no_argument, 0, 'w'},
			{"map-size", no_argument, 0, 'm'},
			{"debug", no_argument, 0, 'd'},
			{0, 0, 0, 0}
		};
	while((c = getopt_long (ac, av, "DL:l:r:t:d:q:p:w:m:d:", long_options,
				&option_index)) != -1) {
		if (long_options[option_index].flag != 0)
			return (0);

		printf("c:%d\n", c);
		transform_debug(c,option_index, debug);
	}
	
	return (0);
}
	
