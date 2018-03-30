/*
** EPITECH PROJECT, 2017
** my lib
** File description:
** get_next_line
*/

#include "header_lib.h"
#include "get_next_line.h"

char	*my_charcat(char *src, char next)
{
	char	*new;
	int	  z;

	z = 0;
	new = malloc(sizeof(char) * my_strlen(src) + 2);
	while (src[z] != '\0') {
		new[z] = src[z];
		z += 1;
	}
	new[z] = next;
	new[z + 1] = '\0';
	return (new);
}

char    *first_one(char next)
{
	char  *new;

	new = malloc(sizeof(char) * 2);
	new[0] = next;
	new[1] = '\0';
	return (new);
}

char		  read_next_char(const int fd)
{
	static	char buf[READ_SIZE];
	static	int z = 0;
	static	int r = 0;
	char		next;

	if (r == z) {
		z = -1;
		while (++z <= READ_SIZE)
			buf[z] = 0;
		if ((r = read(fd, buf, READ_SIZE)) == -1 || r == 0)
			return (-1);
		z = 0;
	} next = buf[z];
	z += 1;
	if (next == '\n' || next == '\0')
		return ((next == '\n') ? '\0' : -1);
	return (next);
}

char	*get_next_line(const int fd)
{
	char	next;
	char	*line;

	line = "";
	next = 'L';
	if (fd < 0)
		return (NULL);
	while (next != '\0') {
		if ((next = read_next_char(fd)) == -1)
			return (NULL);
		else if (line == NULL)
			line = first_one(next);
		else
			line = my_charcat(line, next);
	}
	return (line);
}
