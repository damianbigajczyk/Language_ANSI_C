#include <stdio.h>
#include "exercise_5.h"

int main(int argc, char **argv)
{
	char s[MAX + 1];	

	esettab(argc, argv, s);
	detab(s);

	return 0;
}
