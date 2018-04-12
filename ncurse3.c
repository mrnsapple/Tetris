/*
** EPITECH PROJECT, 2018
** ula
** File description:
** yeahbro
*/

#include <stdlib.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "list.h"

void	print_map(char **av)
{
	for (int i = 0; av[i] != NULL; i++) {
		printw(av[i]);
		printw("\n");
	}
}
