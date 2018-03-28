/*
** EPITECH PROJECT, 2017
** lib
** File description:
** fs
*/

#include "header_lib.h"

fs_t *create_fs(char *str)
{
	fs_t *buf = malloc(sizeof(fs_t));
	buf->pif = 0;
	buf->fprec = 0;
	buf->txt = str;
	return (buf);
}

fs_t *refrs_fs(fs_t *buffer, int a)
{
	buffer->pif += a;
	if (buffer->pif < 0)
		buffer->pif = 0;
	buffer->fprec =	buffer->pif;
	return (buffer);
}