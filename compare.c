/*
** EPITECH PROJECT, 2017
** lib
** File description:
** compare
*/
#include "header_lib.h"

int	my_strcmp(char *s1, char *s2)
{
	int count = 0;
	int i = 0;
	int u = 0;

	if (s2 == NULL)
		return (-1);
	for (;s1[i];i++);
	for (;s2[u];u++);

	if (u != i)
		return (0);

	while (s1[count] != '\0' && s2[count] != '\0' && s1[count] == s2[count])
		count ++;

	if (count != u)
		return (0);
	return (1);
}

int strc_strt(char *source, char *search)
{
	int i = 0;

	if (search == NULL)
		return (-1);
	for (;source[i];i++);
	for (int u = 0;search[u];u++)
		if (u > i)
			return (0);

	for (i = 0;search[i];i++)
		if (source[i] != search[i])
			return (0);
	return (1);
}

int	my_strcmp_end(char *origin, char *end)
{
	int u = 0;
	for (int i = 0;origin[i];i++)
		u = (origin[i] == end[u]) ? u + 1 : 0;
	if (end[u] == '\0')
			return (1);
	return (0);
}

int is_in(char *str, char *source)
{
	int j = 0;
	for (int i = 0;source[i];i++)
	{
		if (source[i] == str[j])
			++j;
		else
			j = 0;
		if (str[j] == '\0')
			return (1);
	}
	return (0);
}