/*
** EPITECH PROJECT, 2018
** dem
** File description:
** de
*/

#include "list.h"

int	help(int ac, char **av)
{
	int	i;

	for (i = ac - 1; i != 0; i--) {
		if (strcom("--help", av[i]) == 1)
			/*my_putstr("sage:  ./tetris [options]$\nOptions$\n--help\nDisplay this help$
-L --level={num}     Start Tetris at level num (def: 1)$
-l --key-left={K}    Move the tetrimino LEFT using the K key (def: left arrow)$
-r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow)$
-t --key-turn={K}    TURN the tetrimino clockwise 90d using the K key (def: top
arrow)$
-d --key-drop={K}    DROP the tetrimino using the K key (def: down arrow)$
-q --key-quit={K}    QUIT the game using the K key (def: `q' key)$
-p --key-pause={K}   PAUSE/RESTART the game using the K key (def: space bar)$
--map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)$
-w --without-next    Hide next tetrimino (def: false)$
-D --debug           Debug mode (def: false)$");*/
			my_putstr("jeje");
	}
	return (0);
}
