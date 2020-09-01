#include <stdio.h>
#include "tab.h"
#include "myctype.h"

static int tabpos(int pos, char *s);

void settab(int argc, char **argv, char *s)
{
	int i, pos;

	if (argc == 1)
		for (i = 1; i <= MAX; i++)
			s[i] = (i % TABINC == 0) ? YES : NO;
	else {
		for (i = 1; i < MAX; i++)
			s[i] = NO;
		while (--argc > 0) {
			pos = atoi_2(*++argv);
			if (pos > 0 && pos <= MAX)
				s[pos] = YES;
		}
	}
}
void entab(char *s)
{
	int c, pos;
	int nb = 0;
	int nt = 0;

	for (pos = 1; (c = getchar()) != EOF; pos++)
		if (c == ' ') {
			if (tabpos(pos, s) == NO)
				++nb;
			else {
				nb = 0;
				++nt;
			}
		} else {
			for ( ; nt > 0; nt--)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else
				for ( ; nb > 0; nb--)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				while (tabpos(pos, s) != YES)
						++pos;
		}
}
void detab(char *s)
{
	int c, pos = 1;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			do
				putchar(' ');
			while (tabpos(pos++, s) != YES);
		else if (c == '\n') {
			putchar(c);
			pos = 1;
		} else {
			putchar(c);
			++pos;
		}
	}
}
void esettab(int argc, char **argv, char *s)
{
	int i, inc, pos;

	if (argc == 1)
		for (i = 1; i <= MAX; i++)
			s[i] = (i % TABINC == 0) ? YES : NO;
	else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') {
		pos = atoi_2(*(argv + 1) + 1);
		inc = atoi_2(*(argv + 2) + 1);
		for (i = 1; i <= MAX; i++)
			if (i != pos)
				s[i] = NO;
			else {
				s[i] = YES;
				pos += inc;
			}
		} else {
		for (i = 1; i < MAX; i++)
			s[i] = NO;
		while (--argc > 0) {
			pos = atoi_2(*++argv);
			if (pos > 0 && pos <= MAX)
				s[pos] = YES;
		}
	}
	
}

/********** Static functions **************/

static int tabpos(int pos, char *s)
{
	return (pos > MAX) ? YES : s[pos];
}
