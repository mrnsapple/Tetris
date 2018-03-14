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

void	order_pieces(pieces_t **list, pieces_t *a)
{
	pieces_t	*tmp;
	pieces_t	*after;
	pieces_t	*b;
	pieces_t	*before = NULL;
	int		i = 0;
	tmp = *list;
	while (tmp->next) {
		
		printf("dir_name%s, nexrt_diname:%s\n", tmp->dir_name, tmp->next->dir_name);
	      	if (alphabetic(tmp->dir_name, tmp->next->dir_name) != 0) {
			after = tmp->next;
			if (tmp->next->next == NULL)
				tmp->next = NULL;
			else
				tmp->next = tmp->next->next;
			after->next = tmp;
			//if (after->next != NULL)
			//	printf("insidedir_name%s, nexrt_diname:%s\n", tmp->dir_name, tmp->next->dir_name);
			printf("i:%d\n", i);
			if (before == NULL || i == 0) {
				a = after;
				*list = a;
				tmp = *list;
				i = -1;
			}
			else {
				b = after;
				*list = a;
				tmp = *list;
				before->next = b;
				i = -1;
			}
			before = tmp;
		}
		else{
			before = tmp;
			tmp = tmp->next;
		}
		i++;
		//a = tmp->next->next;
		print_list(a);

	}
}
/*
void	mv_from_there_all(pieces_t *list, pieces_t *a, char *dir_name)
{
	//char		*new;
	//char		*second;
	pieces_t	*last;
	char		*tmp = 
	last = malloc(sizeof(pieces_t));
	last->next = list->next;
	last->dir_name = dir_name;
	list->next = last; 
	while(tmp) {
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
		}
}
*/
