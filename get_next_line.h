/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** gnl_H_
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef READ_SIZE
# define READ_SIZE 5
# endif

char	*get_next_line(const int fd);

#endif