/*
** EPITECH PROJECT, 2018
** dm
** File description:
** dk
*/

#include "list.h"

char    *file_name(char *name, int i)
{
 	char    *file;
 	char    *a = "tetriminos/";
	int     g;

        file = malloc(sizeof(char) * (my_strlen(name) + 11));
        for (i = 0; a[i] != '\0'; i++)
                file[i] = a[i];
        for (g = 0, i = i; name[g] != '\0'; g++, i++)
                file[i] = name[g];
        file[i] = '\0';
        return (file);
}
char	*delete_after_point(char *name)
{
	int	i;
	
	for (i = 0; name[i] != '\0'; i++);
	name[i - 10] = '\0';
	printf("%s\n",name);
	return (name);
}

int     feed_piece(pieces_t *a, char *name)
{
 	int     fd;
        char    buff[1];
        int     size = 0;
 	char    *file;
	
	file = file_name(name, size);
	a->name = delete_after_point(name);
        printf("%s\n", file);
        fd = open(file, O_RDONLY);//O_CREAT | O_RDWR | O_TRUNC, 0644);
	printf("fd:%d\n",fd);
        if (fd == -1)
                return (0);
	size = read(fd, buff, 1);
	printf("size:%d\n", size);
	for (size = read(fd, buff, 1); size > 0;
             size = read(fd, buff, 1)) {
                //printf("buf:%c\n", buff[0]);
		a->color = '1';
        }
        return (1);
}

void	feed_linked_list(pieces_t **a)
{
	pieces_t	*list = *a;

	while(list) {
		feed_piece(list, list->dir_name);
		list = list->next;
	}
}
