/*
** EPITECH PROJECT, 2018
** dkss
** File description:
** dkss
*/

#include "../list.h"

char	*file_name(char *name, int i)
{
	char    *file;
	char    *a = "tetriminos/";
	int     g;

	file = malloc(sizeof(char) * (my_strlen(name) + 25));
	for (i = 0; a[i] != '\0'; i++)
		file[i] = a[i];
	for (g = 0, i = i; name[g] != '\0'; g++, i++)
		file[i] = name[g];
	file[i] = '\0';
	return (file);
}

char	*delete_after_point(char *name)
{
 	int     i;

	for (i = 0; name[i] != '\0'; i++);
	name[i - 10] = '\0';
	return (name);
}

void	error_piece_next_line(int *y, int *x_uno, int *x_dos)
{
	(*y)++;
	if ((*x_uno) < (*x_dos) && *y != 1)
		(*x_uno) = *x_dos;
	*x_dos = 0;
}
