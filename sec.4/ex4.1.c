#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	FILE *pf = fopen("text", "r");
	char buff[MAX];
	char *find = "ould";

	if (!pf) {
		fprintf(stderr, "Failed to open file \"text\"\n");
		return -1;
	}
	while (getLine(pf, buff, MAX)) {
		static int i = 1;
		int pos;
		if ((pos = strindex(buff, find)) != -1)
			fprintf(stdout, "Line: %d Position: %d %s\n", i, pos, buff + pos);
		++i;
	}

	return 0;
}
