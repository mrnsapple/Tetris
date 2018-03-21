/*
** EPITECH PROJECT, 2018
** dem
** File description:
** de
*/

#include "list.h"

int	help(int ac, char **av)
{
	my_putstr("Usage:  ./tetris [options]$\nOptions$\n-");
	my_putstr("-help\nDisplay this help$\n-L --level={num}");
	my_putstr("Start Tetris at level num (def: 1)$\n-l --");
	my_putstr("key-left={K}    Move the tetrimino LEFT usi");
	my_putstr("ng the K key (def: left arrow)$-r --key-rig");
	my_putstr("ht={K}   Move the tetrimino RIGHT using the ");
	my_putstr("K key (def: right arrow)$-t --key-turn={K}  ");
	my_putstr("TURN the tetrimino clockwise 90d using the K ");
	my_putstr("key (def: top arrow)$ -d --key-drop={K}    DR");
	my_putstr("OP the tetrimino using the K key (def: down ar");
	my_putstr("row)$ -q --key-quit={K}    QUIT the game using ");
	my_putstr("the K key (def: `q' key)$ -p --key-pause={K}  ");
	my_putstr("PAUSE/RESTART the game using the K key (def: s");
	my_putstr("pace bar)$ --map-size={row,col} Set the numbers");
	my_putstr("of rows and columns of the map (def: 20,10)$ -w");
	my_putstr("--without-next    Hide next tetrimino (def: fals");
	my_putstr("e)$ -D --debug           Debug mode (def: false)$");
	return (0);
}
