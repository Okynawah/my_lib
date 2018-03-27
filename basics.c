/*
** EPITECH PROJECT, 2017
** lib
** File description:
** un
*/

#include "header_lib.h"

char *merge_str(char *princ, char *scd)
{
	int i = my_strlen(princ);
	int u = my_strlen(scd);
	int y = 0;
	char *retour = malloc(sizeof(char) * (i + u + 1));

	for (;y < (i + u);y++)
		retour[y] = (y < i) ? princ[y] : scd[y-i];
	retour[i + u] = '\0';
	return (retour);
}


char *parser(char *str, char *s)
{
	static char *save = NULL;
	int i = 0;
	char *rt = NULL;

	for (;str[i];i++)
		if (strcomp_start(reduce_from(str, i), s))
			break;
	if (i >= my_strlen(str))
		return (NULL);
	if (strcomp_start(str, save) == 1)
		rt = malloc(sizeof(char) * my_strlen(str) - (my_strlen(s) + i));
	else
		rt = malloc(sizeof(char) * i);
	i = (strcomp_start(str, save) != 1) ? 0 : i + my_strlen(s);
	for (int j = 0;str[i] && !strcomp_start(reduce_from(str, i), s);i++, j++)
		rt[j] = str[i];
	return (save = rt);
}

char *reduce_from(char *str, int from)
{
	char *rt = malloc(sizeof(char) * (my_strlen(str) - from));
	for (int i = from;str[i];i++)
		rt[i - from] = str[i];
	return (rt);
}

int word_counter(char *str)
{
	int counter = 0;
	int i = 0;
	while(1) {
		for (; str[i] != ' '; i++)
			if (str[i] == '\0')
				return (counter + 1);
		i++;
		counter++;
	}
	return (0);
}

int next_space(char *str, int o)
{
	int i = o;
	for (;str[i];i++)
		if (str[i] == ' ' || str[i] == '\n')
			return (i - o);

	return (i - o);
}