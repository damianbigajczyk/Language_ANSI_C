#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exercise_5.h"
#include "sort.h"

#define NUMERIC 1
#define DEC 2
#define FOLD 4
#define DIRECT 8
#define MAX 100
#define MAXLINES 100

void error(char *);
void readargs(int argc, char **argv);
void substr(char *s, char *str);
int numcmp_3(char *s1, char *s2);
int charcmp_3(char *s1, char *s2);


char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char **argv)
{
	char *lineptr[MAXLINES];
	int nlines = 0;

	readargs(argc, argv);
	if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
		if (option & NUMERIC)
			qsort_2((void **) lineptr, 0, nlines-1,
					(int (*) (void *, void *)) numcmp_3);
		else
			qsort_2((void **) lineptr, 0, nlines-1,
					(int (*) (void *, void *)) charcmp_3);
		writelines_2(lineptr, nlines, option & DEC);
	} else
		error("Input too big to sort");

	return 0;
}
void error(char *s)
{
	fprintf(stderr, "%s\n", s);
	exit(EXIT_FAILURE);
}
void readargs(int argc, char **argv)
{
	int c;

	while ((--argc > 0 && ((c = (*++argv)[0]) == '-' || c == '+'))) {
		if (c == '-' && !isdigit(*(argv[0] + 1)))
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
		else if (c == '-')
			pos2 = atoi(argv[0] + 1);
		else if ((pos1 = atoi(argv[0] + 1) < 0))
			error("Usage: sort -dfnr [+pos1] [-pos2]");
	}
	if (argc || pos1 > pos2)
		error("Usage: sort -dfnr [+pos1] [-pos2]");
}
int numcmp_3(char *s1, char *s2)
{
	double v1, v2;
	char str[MAX];

	substr(s1, str);
	v1 = atof(str);
	substr(s2, str);
	v2 = atof(str);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
void substr(char *s, char *str)
{
	extern int pos1, pos2;
	int i, j, len;

	len = strlen(s);

	if (pos2 > 0 && len > pos2)
		len = pos2;
	else if (pos2 > 0 && len < pos2)
		error("substr: string too short");
	for (j = 0, i = pos1; i < len; i++, j++)
		str[j] = s[i];
	str[j] = '\0';
}
int charcmp_3(char *s1, char *s2)
{
	extern int pos1, pos2;
	extern char option;
	int endpos;
	char a, b;
	int fold = (option & FOLD) ? 1 : 0;
	int direct = (option & DIRECT) ? 1 : 0;
	int i = pos1;
	int j = pos1;

	if (pos2 > 0)
		endpos = pos2;
	else if ((endpos = strlen(s1)) > strlen(s2))
		endpos = strlen(s2);
	do {
		if (direct) {
			while (i < endpos && !isalnum(s1[i]) && s1[i] != ' ' && s1[i] != '\0')
				i++;
			while (j < endpos && !isalnum(s2[j]) && s2[j] != ' ' && s2[j] != '\0')
				j++;
		}
		if (i < endpos && j < endpos) {
			a = fold ? tolower(s1[i]) : s1[i];
			i++;
			b = fold ? tolower(s2[j]) : s2[j];
			j++;
			if (a == b && a == '\0')
				return 0;
		}
	} while (a == b && i < endpos && j < endpos);
	return a - b;
}
