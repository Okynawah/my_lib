/*
** EPITECH PROJECT, 2017
** lib
** File description:
** print
*/
#include "header_lib.h"

void print(char *str)
{
	int len;

	if (!str)
		return;
	if ((len = my_strlen(str)) <= 0)
		return;
	write(1, str, len);
}

void printc(char str)
{
	write(1, &str, 1);
}

void printn(char *str)
{
	char c = '\n';
	print(str);
	write(1, &c, 1);
}