#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct pos
{
	int y;
	int x;
} pos_t;

typedef struct stat
{
	int pif;
	int fprec;
	char *text;
}fsta_t;

char *merge_str(char *princ, char *scd);
char *parser(char *str, char *s);
char *reduce_from(char *str, int from);
int word_counter(char *str);
int next_space(char *str, int o);
int my_strlen(char *str);
char *st(char c);
void print(char *str);
int	my_strcmp(char *s1, char *s2);
int strcomp_start(char *source, char *search);
int	my_strcmp_end(char *origin, char *end);
int height_per_i(char *text, int i);
char *conv_int_str(int nbr);
char *my_revstr(char *str);
char *array_to_str(int argc, char **argv);
pos_t *strlen_array(int argc, char **argv);
char *gnw(fsta_t *sta);
char *gng(fsta_t *sta);
int is_in(char *str, char *source);
char *uptog(char *str);
int strle_nw(fsta_t *stat);
fsta_t *create_fsta(char *text);
fsta_t *refrs_fsta(fsta_t *buffer, int a);
char **str_to_array(fsta_t *sta);
