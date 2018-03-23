/*
** EPITECH PROJECT, 2017
** lib
** File description:
** chibi
*/
#include "header_lib.h"

int my_strlen(char *str)
{
	int rt = 0;
	for (; str[rt]; rt++);
	return (rt);
}

char *st(char c)
{
	char *rt = malloc(sizeof(char) + sizeof(char));
	rt[0] = c;
	rt[1] = '\0';
	return (rt);
}

void my_putstr(char *str)
{
	for (int i = 0, c = str[0];str[i];++i, c = str[i])
		write(1, &c, 1);
}
