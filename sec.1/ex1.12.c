#include <stdio.h>

#define START 0
#define STOP 1

int main(int argc, char *argv[])
{
	FILE *pf = fopen("poem", "r");
	int c;
	int state = START;

	if (!pf) {
		puts("Faile to open file: \"poem\"");
		return -1;
	}
	while ((c = fgetc(pf)) != EOF) {
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
			state = START;
			putchar(c);
		} else {
			if (state)
				continue;
			state = STOP;
			putchar('\n');
		}
	}
	fclose(pf);

	return 0;
}
