/*
** EPITECH PROJECT, 2018
** navi
** File description:
** puts
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../list.h"

int	my_strlen(char *av)
{
	int	i;

	for (i = 0; av[i] != '\0'; i++);
	return (i);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;
	
	while(str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

int	my_strcmp(char *pwd, char *line)
{
	int     i;

	for (i = 0; line[i] != '\0'; i++)
		if(pwd[i] != line[i])
			return (0);
	return (1);
}

int	is_num(char *str)
{
	int	i;
	int	g = 1;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != '+' &&
		    (str[i] < '0' || str[i] > '9'))
			g = 0;
	if (g == 1)
		return (1);
	return (0);
}
