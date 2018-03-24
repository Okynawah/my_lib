#include <stdio.h>
#include "header_lib.h"

int main()
{
	fsta_t *sta = create_fsta();
	char *a = "abcd efg hij \"oui\"";
	char *buf;
	refrs_fsta(sta, strlew(a, sta));
	refrs_fsta(sta, strlew(a, sta));
	refrs_fsta(sta, strlew(a, sta));
	print(gng(a, sta));

	return 0;
}