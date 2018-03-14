/*
** EPITECH PROJECT, 2018
** dk
** File description:
** del
*/

#include "list.h"

void    print_list(pieces_t *a)
{
        pieces_t        *tmp;

        tmp = a;
	while (tmp != NULL) {
	        printf("list:%s\n",tmp->dir_name);
                tmp = tmp->next;
        }
}


void	mv_from_there_all(pieces_t *list, pieces_t *a, char *dir_name)
{
	//char		*new;
	//char		*second;
	pieces_t	*last;

	last = malloc(sizeof(pieces_t));
	last->next = list->next;
	last->dir_name = dir_name;
	list->next = last; 
	/*while(tmp) {
		 printf("mv:%s\n",tmp->dir_name);
		 tmp = tmp->next;
        }
	tmp = *list;
	new = dir_name;
	while(tmp) {
		second = tmp->dir_name;
		tmp->dir_name = new;
		printf("tmp->dir:%s\n", tmp->dir_name);
		new = second;
		tmp = tmp->next;
	}
	tmp = last;
	tmp = *list;
	while(tmp) {
		printf("mv:%s\n",tmp->dir_name);
                tmp = tmp->next;
		}*/
}
