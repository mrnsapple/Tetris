/*
** EPITECH PROJECT, 2018
** aimo
** File description:
** orio
*/

#include "../list.h"

int	its_num(char *a)
{
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] < '0' || a[i] > '9')
			return (0);
	return (1);
}

char	*modify_flag(char *a)
{
	if (my_strcmp(a, " "))
		return ("(space)");
	if (a[0] != '\0')
		a[1] = '\0';
	return (a);
}

int	transform_debug(int c, int option_index, debug_t *debug)
{
	
	char	*flag = NULL;

	flag = optarg;
	if (c == '?')
		return (0);
	if (flag == NULL)
		return (1);
	flag = modify_flag(flag);
	if (c == 'L') {
		if (its_num(flag) == 0)
			return (1);
		debug->level = flag;
	}
	transform_debug_second(flag, c , option_index, debug);
	return (1);
}

int	getopt_use(int ac, char **av, debug_t *debug)
{
	int	option_index = 0;
	int	c;
	printf("hehe\n");
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
			{"debug", no_argument, 0, 'D'},
			{0, 0, 0, 0}
		};
	while((c = getopt_long (ac, av, "DL:l:r:t:d:q:p:w:m:d:", long_options,
				&option_index)) != -1) {
		if (long_options[option_index].flag != 0)
			return (0);
		if (transform_debug(c, option_index, debug) == 0)
			return (0);
	}
	return (1);
}