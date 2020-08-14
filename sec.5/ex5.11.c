#include <stdio.h>
#include "exercise_5.h"

int main(int argc, char **argv)
{
	char s[MAX + 1];	

	settab(argc, argv, s);
	entab(s);

	return 0;
}
