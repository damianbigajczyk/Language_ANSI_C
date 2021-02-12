#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int c;

	if (argc < 2) {
		fprintf(stderr, "Usage: ./%s [option]\n", argv[0]);
		return 0;
	}

	if (!strcmp(argv[1], "lower"))
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else if (!strcmp(argv[1], "upper"))
		while ((c = getchar()) != EOF)
			putchar(toupper(c));
	else
		while ((c = getchar()) != EOF)
			putchar(c);
	return 0;
}
