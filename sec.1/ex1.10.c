#include <stdio.h>

int main(void)
{
	char c;
	puts("Input your text or press '#' to end");
	while ((c = getchar()) != '#') {
		if (c == '\t')
			fputs("'\\t'", stdout);
		else if (c == '\b')
			fputs("'\\b'", stdout);
		else if (c == '\\')
			fputs("\\\\", stdout);
		else
			putchar(c);
	}

	return 0;
}
