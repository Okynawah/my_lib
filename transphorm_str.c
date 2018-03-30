/*
** EPITECH PROJECT, 2017
** lib
** File description:
** transphorm
*/
#include "header_lib.h"

char 	*conv_int_str(int nbr)
{
	char *rt;
	int i = 0; 
	int lenght = nbr;

	if (!nbr)
		return 0;
	for (int j = 0;lenght > 0;lenght/=10, j++);
	rt = malloc(sizeof(char) * (lenght + 1));
	for (;nbr > 0;i++) {
		rt[i] = (nbr%10) + 48;
		nbr /= 10;
		i++;
	}

	rt[i] = '\0';
	rt = my_revstr(rt);
	return (char *)(rt);
}

char *my_revstr(char *str)
{
	int i,n,m,z;
	char y;

	for (i = 0;str[i];i++);
	n = 0;
	m = i;
	z = m;

	while (n + m == i && m != z / 2) {
		y = str[m];
		str[m] = str[n];
		str[n] = y;
		n = n + 1;
		m = m - 1;
	}
	return (str);
}

int conv_str_int(char *str)
{
	int i = 0;
	int neg = 1;
	long num = 0;

	for (;str[i] == '-' || str[i] == '+';i++)
		neg = (str[i] == '-') ? neg * -1 : neg;

	for (;str[i] > 47 && str[i] < 58 && str[i] != '\0';i++) 
		num = (str[i] > 47 && str[i] < 58) ? (num * 10) + str[i] - 48 : num;
	return ((num > 2147483648 &&(neg == -1 || neg == 1)) ? 0 : num * neg);
}