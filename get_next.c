/*
** EPITECH PROJECT, 2017
** lib
** File description:
** array
*/
#include "header_lib.h"

char *gnw(char *text)
{
	char *rt;
	int j = 0;
	static int i = 0;

	for (;text[i] && (text[i] == '\n' || text[i] == ' ');i++);
	rt = malloc(sizeof(char) * (strlew(text, i)+1));
	for (;text[i]; i++) {
		rt[j] = text[i];
		if (text[i+1] == ' ' || text[i+1] == '\n') {
			i+=2;
			rt[j+1] = '\0';
			if (text[i - 1] == '\n') {
				realloc(rt, strlew(text, i) + 2);
				rt[j+1] = text[i-1];
				rt[j+2] = '\0';
			}
			return (rt);
		}
		j++;
	}
	rt[j+1] = '\0';
	return (rt);
}

int gng(char *text, char *buffer)
{
	int len = 1, compteur = 0;
	static int i = 0;
	i += strlew(text, i);

	for (;text[i] && (text[i] != '\n' || compteur < 2);i++)
		compteur = (text[i] == '"') ? compteur + 1 : compteur;

	if (compteur != 2)
		exit(84);

	do {
		len += strlew(text, i) + 1;
		printf("%d\n", len);
		realloc(buffer,len + 1);
		buffer = merge_str(buffer, gnw(text));
		i += strlew(text, i);
	} while (!is_in(st('\"'), buffer));
	buffer[sizeof(buffer)] = '\0';
	return (uptog(buffer));
}

char *uptog(char *str)
{
	char *rt = malloc(sizeof(char) * (my_strlen(str) - 1));
	int i = 1;

	for (;str[i];i++) {
		if (str[i] == '\"')
			break;
		rt[i-1] = str[i];
	}
	rt[i] = '\0';
	return (rt);
}

int strlew(char *text, int pif)
{
	int save = pif;
	if (text[++pif] != ' ')
		for (;text[pif];pif++)
			if (text[pif] != ' ' && text[pif] != '\n')
				break;

	for (;text[pif];pif++)
		if (text[pif] == ' ' || text[pif] == '\n')
			break;
	return (pif - save);
}