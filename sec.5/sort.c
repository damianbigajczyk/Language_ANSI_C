#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "sort.h"
#include "mystring.h"
#include "myctype.h"

static void swap(char *v[], int i, int j);
static void swap_2(void *v[], int i, int j);

void qsort_1(char *v[], int left, int right)
{
	int i, last;
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (mystrcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort_1(v, left, last-1);
	qsort_1(v, last+1, right);
}
void qsort_2(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	
	if (left >= right)
		return;
	swap_2(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap_2(v, ++last, i);
	swap_2(v, left, last);
	qsort_2(v, left, last-1, comp);
	qsort_2(v, last+1, right, comp);

}
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
int charcmp(char *s1, char *s2)
{
	for ( ; tolower(*s1) == tolower(*s2); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return tolower(*s1) - tolower(*s2);
}

/****** Static functions ******/

static void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
static void swap_2(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
