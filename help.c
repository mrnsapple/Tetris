/*
** EPITECH PROJECT, 2018
** dem
** File description:
** de
*/

#include "list.h"

int	help(int ac, char **av)
{
	int	fd;
	char	buff[2];
	int	size = 0;

	fd = open("help_text" , O_RDONLY, 0644);
	if (fd == -1)
		return (0);
	for (size = read(fd, buff, 1); size > 0;
	     size = read(fd, buff, 1))
		my_putchar(buff[0]);
	return (0);
}
