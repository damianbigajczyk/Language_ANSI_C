#include <stdio.h>
#include "tab.h"

int main(int argc, char **argv)
{
	char s[MAX + 1];	

	esettab(argc, argv, s);
	detab(s);

	return 0;
}
