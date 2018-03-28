#include <stdio.h>
#include "header_lib.h"

int main()
{
	/*
	fs_t *sta = create_fs();
	char *a = "abcd efg hij \"oui\"";
	print(parser(a, st('e')));
	*/
	fs_t *a = create_fs("djd oijoij ijoj  ijiv y o huho");
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));
	print(gnw(a));

	//print(parser(text, "ijoj"));
	//print(parser(text, "ijoj"));

	return 0;
}