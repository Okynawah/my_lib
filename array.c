/*
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
