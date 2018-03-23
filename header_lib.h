#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct pos
{
	int y;
	int x;
} pos_t;

char *merge_str(char *princ, char *scd);
char *parser(char *str, char *s);
char *reduce_from(char *str, int from);
int word_counter(char *str);
int next_space(char *str, int o);
int my_strlen(char *str);
char *st(char c);
void my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
int strcomp_start(char *source, char *search);
int	my_strcmp_end(char *origin, char *end);
int height_per_i(char *text, int i);
char *conv_int_str(int nbr);
char *my_revstr(char *str);
char *array_to_str(int argc, char **argv);
pos_t *strlen_array(int argc, char **argv);
char *gnw(char *text);
int gng(char *text, char *buffer);
int is_in(char *str, char *source);
char *uptog(char *str);
int strlew(char *text, int pif);
