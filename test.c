#include <stdio.h>
#include "header_lib.h"

int main()
{
	/*
	fsta_t *sta = create_fsta();
	char *a = "abcd efg hij \"oui\"";
	print(parser(a, st('e')));
	*/
	fsta_t *a = create_fsta("djd oijoij ijoj  ijiv y o huho");
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));

	//print(parser(text, "ijoj"));
	//print(parser(text, "ijoj"));

	return 0;
}