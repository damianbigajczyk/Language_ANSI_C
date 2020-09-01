#include <stdio.h>
#include "exercise_5.h"
#include "sort.h"
#include "mystring.h"

#define MAXLINES 5000
#define NUMERIC 1
#define DEC 2

int main(int argc, char **argv)
{
	char option = 0;
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
					(int (*)(void*, void*)) mystrcmp);
		writelines_2(lineptr, nlines, option & DEC);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}
