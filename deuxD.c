/*
** EPITECH PROJECT, 2017
** lib
** File description:
** 2D
*/
#include "header_lib.h"

int height_per_i(char *text, int i)
{
	int n = 0;
	for (int u = 0;text[u]; u++) {
		if (text[u] == '\n')
			n++;
		if (u >= i)
			return n;
	}
	return 0;
}
