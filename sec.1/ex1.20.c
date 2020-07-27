#include <stdio.h>

#define TAB 6

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		if (c == '\t')
			for (int i = 0; i < TAB; i++)
				putchar(' ');
		else
			putchar(c);


	return 0;
}
