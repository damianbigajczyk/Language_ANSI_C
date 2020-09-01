#include <stdio.h>
#include "tab.h"

int main(int argc, char **argv)
{
	char s[MAX + 1];	

	settab(argc, argv, s);
	entab(s);

	return 0;
}
