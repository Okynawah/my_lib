/*
** EPITECH PROJECT, 2017
** lib
** File description:
** get next
*/
#include "header_lib.h"

int condit(char c)
{
	if (!c)
		return (0);
	return (c == '\n' || c == ' ') ? 1 : 0;
}

char *gnw(fs_t *s)
{
	char *rt;
	int count;
	for (;condit(s->txt[s->pif]);++s->pif);
	count = strle_nw(s);
	rt = malloc(sizeof(char) * (count + 1));
	for (int j = 0;s->txt[s->pif]; s->pif++, j++) {
		rt[j] = s->txt[s->pif];
		if (s->txt[s->pif+1] == ' ' || s->txt[s->pif+1] == '\n') {
			s->pif+=1;
			rt[j+1] = '\0';
			break;
		}
	}
	rt[count] = '\0';
	return (rt);
}

char *gng(fs_t *s)
{
	int srt = 0;
	int end = 0;
	int compteur = 0;
	char *rt = NULL;
	for (int i = s->pif;s->txt[i] && compteur < 2;i++) {
		compteur = (s->txt[i] == '"') ? compteur + 1 : compteur;
		srt = (compteur == 0) ? i+1 : srt;
		end = (compteur == 1) ? i+1 : end;
	}

	if (compteur != 2)
		return (rt);
	rt = malloc(sizeof(char) * (end - srt));
	do {
		rt = merge_str(rt, gnw(s));
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

int strle_nw(fs_t *st)
{
	int i = st->pif;
	for (;st->txt[i] == ' ' || st->txt[i] == '\t'
		|| st->txt[i] == '\n'; i++);
	if (st->txt[i] != ' ')
		for (;st->txt[i];i++)
			if (st->txt[i] == ' ' || st->txt[i] == '\n')
				break;
	for (;st->txt[i];i++)
		if (st->txt[i] == ' ' || st->txt[i] == '\n')
			break;
	return (i - st->pif);
}