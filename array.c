/*r
** EPITECH PROJECT, 2017
** lib
** File description:
** array
*/
#include "header_lib.h"

char *array_to_str(int argc, char **argv)
{
	pos_t *stat = strlen_array(argc, argv);
	int pos = 0;
	char *rt = malloc(sizeof(stat->x + 1));

	for (int i = 1; i < argc; i++) {
		for (int k = 0;argv[i][k]; k++) {
			rt[pos] = argv[i][k];
			pos++;
		}
		if (pos < (stat->x - stat->y)) {
			rt[pos] = ' ';
			pos++;
		}
	}
	rt[pos+1] = '\0';
	return (rt);
}

pos_t *strlen_array(int argc, char **argv)
{
	pos_t *rt;
	rt = malloc(sizeof(pos_t));
	rt->x = 0;
	rt->y = 0;

	for (int i = 1; i < argc;i++, rt->x++)
		for (rt->y = 0; argv[i][rt->y]; rt->y++, rt->x++);
	return (rt);
}

char **str_to_array(fsta_t *sta)
{
	int compt = 0;
	int u = 0;
	int size = word_counter(sta->text);
	char **tab;

	tab = malloc(sizeof(char *) * (size + 1));
	tab[compt] = malloc(sizeof(char) * (strle_nw(sta) + 1));

	for (int i = 0;sta->text[i]; i++)
		if (sta->text[i] == ' ')
			if (sta->text[i-1] == ' ')
				i++;
			else {
				compt++;
				tab[compt] = malloc(sizeof(char) * (strle_nw(sta)- 1));
				u = 0;
			}
		else {
			tab[compt][u] = sta->text[i];
			u++;
		}
	return(tab);
}
