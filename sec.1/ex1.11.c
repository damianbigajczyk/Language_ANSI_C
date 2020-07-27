#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *pf = fopen("poem", "r");
	enum state {false, true} flag;
	int c, nl, nw, nc;

	if (!pf) {
		puts("Faile to open file: \"poem\"");
		return -1;
	}

	flag = false;
	nl = nw = nc = 0;

	while ((c = fgetc(pf)) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			flag = true;
		else if (flag) {
			flag = false;
			++nw;
		}
	}
	printf("lines: %d\twords: %d\tsigns: %d\n",
			nl, nw, nc);
	fclose(pf);

	return 0;
}
