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

char *upton(char *str)
{
	int i = 0;
	char *rt;
	for (;str[i];i++)
		if (str[i] == '\n')
			break;
	rt = malloc(sizeof(char) * (i + 1));
	for (int j = 0; j < i; j++)
		rt[j] = str[j];
	rt[i] = '\0';
	return (rt);
}