/*
** EPITECH PROJECT, 2017
** lib
** File description:
** transphorm
*/
#include "../../include/libc.h"
#include <stdlib.h>

char 	*conv_int_str(int nbr)
{
	char *rt = NULL;
	int lenght = nbr;
	int j = 0;

	if (!nbr)
		return (NULL);
	for (; lenght > 0; ++j)
		lenght /= 10;
	rt = malloc(sizeof(char) * (j + 1));
	rt[j] = '\0';

	for (int i = j-1; nbr > 0;i--) {
		rt[i] = nbr%10 + 48;
		nbr /= 10;
	}

	return (char *)(rt);
}

int conv_str_int(char *str)
{
	int i = 0;
	int neg = 1;
	long num = 0;

	for (;str[i] == '-' || str[i] == '+';i++)
		neg = (str[i] == '-') ? neg * -1 : neg;

	for (;str[i] > 47 && str[i] < 58 && str[i] != '\0';i++)
		if (str[i] > 47 && str[i] < 58)
			num = (num * 10) + str[i] - 48;
	return ((num > 2147483648 &&(neg == -1 || neg == 1)) ? 0 : num * neg);
}

char    *my_strcpy(char *str)
{
	int max = my_strlen(str);
	char *rt = malloc(sizeof(char) * (max + 1));

	if (!rt)
		return (NULL);
	for (int i = 0;str[i];i++)
		rt[i] = str[i];
	rt[max] = '\0';
	return (rt);
}

char *cut_from(char *str, int until, fs_t *buff)
{
	int i = 0;
	char *rt = malloc(sizeof(char) * (until + 1));
	int len = my_strlen(str);
	if (!str)
		return (NULL);
	if (len < until)
		return (NULL);
	for (i = 0; i < until;i++)
		rt[i] = str[i];
	if (buff != NULL)
		buff->pif -= len - until - 1;
	return (rt);
}
