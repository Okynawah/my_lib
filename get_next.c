/*
** EPITECH PROJECT, 2017
** lib
** File description:
** get next
*/
#include "header_lib.h"

char *gnw(fsta_t *sta)
{
	char *rt;
	for (;sta->text[sta->pif] && (sta->text[sta->pif] == '\n' || sta->text[sta->pif] == ' ');++sta->pif);
	rt = malloc(sizeof(char) * strle_nw(sta));
	for (int j = 0;sta->text[sta->pif]; sta->pif++, j++) {
		rt[j] = sta->text[sta->pif];
		if (sta->text[sta->pif+1] == ' ' || sta->text[sta->pif+1] == '\n') {
			sta->pif+=1;
			rt[j+1] = '\0';
			break;
		}
	}
	rt[sizeof(rt)] = '\0';
	return (rt);
}

char *gng(fsta_t *sta)
{
	int start = 0;
	int end = 0;
	int compteur = 0;
	char *rt = NULL;

	for (int i = sta->pif;sta->text[i] && compteur < 2;i++)
	{
		compteur = (sta->text[i] == '"') ? compteur + 1 : compteur;
		start = (compteur == 0) ? i+1 : start;
		end = (compteur == 1) ? i+1 : end;
	}

	if (compteur != 2)
		return (rt);
	rt = malloc(sizeof(char) * (end - start));
	do {
		rt = merge_str(rt, gnw(sta));
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

int strle_nw(fsta_t *stat)
{
	int i = stat->pif;
	int j = i;
	for (;stat->text[j] == ' ' || stat->text[j] == ' '; ++j);
	i = j;
	if (stat->text[i] != ' ')
		for (;stat->text[i];i++)
			if (stat->text[i] != ' ' && stat->text[i] != '\n')
				break;

	for (;stat->text[i];i++)
		if (stat->text[i] == ' ' || stat->text[i] == '\n')
			break;
	return (stat->pif - (stat->fprec - j));
}

fsta_t *create_fsta(char *str)
{
	fsta_t *buf = malloc(sizeof(fsta_t));
	buf->pif = 0;
	buf->fprec = 0;
	buf->text = str;
	return (buf);
}

fsta_t *refrs_fsta(fsta_t *buffer, int a)
{
	buffer->pif += a;
	if (buffer->pif < 0)
		buffer->pif = 0;
	buffer->fprec =	buffer->pif;
	return (buffer);
}