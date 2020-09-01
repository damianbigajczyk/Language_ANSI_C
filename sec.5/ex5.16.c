#include <stdio.h>
#include <ctype.h>
#include "exercise_5.h"
#include "sort.h"
#include "mystring.h"

#define MAXLINES 5000
#define NUMERIC 1
#define DEC 2
#define FOLD 4
#define DIRECT 8

char option = 0;

int charcmp_2(char *s1, char *s2);

int main(int argc, char **argv)
{
	char *lineptr[MAXLINES];
	int nlines, c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			switch (c) {
				case 'n':
					option |= NUMERIC;
					break;
				case 'r':
					option |= DEC;
					break;
				case 'f':
					option |= FOLD;
					break;
				case 'd':
					option |= DIRECT;
					break;
				default:
					printf("illegal option %c\n", c);
					argc = 1;
					break;
			}
	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		if (option & NUMERIC)
			qsort_2((void**) lineptr, 0, nlines-1,
					(int (*)(void*, void*)) numcmp);
		else
			qsort_2((void**) lineptr, 0, nlines-1,
					(int (*)(void*, void*)) charcmp_2);
		writelines_2(lineptr, nlines, option & DEC);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}
int charcmp_2(char *s1, char *s2)
{
	char a, b;
	int fold = (option & FOLD) ? 1 : 0;
	int direct = (option & DIRECT) ? 1 : 0;

	do {	
		if (direct) {
			while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
				++s1;
			while (!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
				++s2;
		}
		a = fold ? tolower(*s1) : *s1;
		++s1;
		b = fold ? tolower(*s2) : *s2;
		++s2;
		if (a == b && a == '\0')
			return 0;
	} while (a == b);
	return a-b;
}
