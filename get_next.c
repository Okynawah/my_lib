/*
** EPITECH PROJECT, 2017
** lib
** File description:
** array
*/
#include "header_lib.h"

char *gnw(char *text, fsta_t *sta)
{
	char *rt;
	for (;text[sta->pif] && (text[sta->pif] == '\n' || text[sta->pif] == ' ');++sta->pif);
	rt = malloc(sizeof(char) * strlew(text, sta));
	for (int j = 0;text[sta->pif]; sta->pif++, j++) {
		rt[j] = text[sta->pif];
		if (text[sta->pif+1] == ' ' || text[sta->pif+1] == '\n') {
			sta->pif+=1;
			rt[j+1] = '\0';
			break;
		}
	}
	rt[sizeof(rt)] = '\0';
	return (rt);
}

char *gng(char *text, fsta_t *sta)
{
	int start = 0;
	int end = 0;
	int compteur = 0;
	char *rt;

	for (int i = sta->pif;text[i] && compteur < 2;i++)
	{
		compteur = (text[i] == '"') ? compteur + 1 : compteur;
		start = (compteur == 0) ? i+1 : start;
		end = (compteur == 1) ? i+1 : end;
	}

	if (compteur != 2)
		return (rt);
	rt = malloc(sizeof(char) * (end - start));
	do {
		rt = merge_str(rt, gnw(text, sta));
		rt[my_strlen(rt)] = ' ';
	} while (!is_in(st('\"'), rt));
	rt[sizeof(rt)] = '\0';
	return (uptog(rt));
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

int strlew(char *text, fsta_t *stat)
{
	int i = stat->pif;
	int j = i;
	for (;text[j] == ' ' || text[j] == ' '; ++j);
	i = j;
	if (text[i] != ' ')
		for (;text[i];i++)
			if (text[i] != ' ' && text[i] != '\n')
				break;

	for (;text[i];i++)
		if (text[i] == ' ' || text[i] == '\n')
			break;
	return (stat->pif - (stat->fprec - j));
}

fsta_t *create_fsta(void)
{
	fsta_t *buf = malloc(sizeof(fsta_t));
	buf->pif = 0;
	buf->fprec = 0;
	return (buf);
}

fsta_t *refrs_fsta(fsta_t *buffer, int a)
{
	buffer->pif += a;
	buffer->fprec =	buffer->pif;
	return (buffer);
}