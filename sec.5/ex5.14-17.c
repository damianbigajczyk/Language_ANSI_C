#include <stdio.h>
#include <string.h>
#include "exercise_5.h"

#define MAXLINES 5000
#define NUMERIC 1
#define DEC 2
#define FOLD 4

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
				case 'f':
					option |= FOLD;
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
		else if (option & FOLD)
			qsort_2((void**) lineptr, 0, nlines-1,
					(int (*)(void*, void*)) charcmp);
		else
			qsort_2((void**) lineptr, 0, nlines-1,
					(int (*)(void*, void*)) strcmp_2);
		writelines_2(lineptr, nlines, option & DEC);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}
