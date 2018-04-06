/*
** EPITECH PROJECT, 2018
** dk
** File description:
** dk
*/

#include "../list.h"

void    error_piece_next_line(int *y, int *x_uno, int *x_dos)
{
	(*y)++;
	if ((*x_uno) < (*x_dos) && *y != 1)
		(*x_uno) = *x_dos;
	*x_dos = 0;
}
