#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercise_5.h"

#define BUFSIZE 100
#define ALLOCSIZE 10000

static char buf[BUFSIZE];
static int bufp;

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

static int getch(void);
static void ungetch(int c);
static int getLine(char *line, size_t n);
static char *alloc(size_t n);
static void afree(char *p);
static void swap(char *v[], int i, int j);

int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch()))
		continue;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		d = c;
		if (!isdigit(c = getch())) {
			if (c != EOF) {
				ungetch(d);
				ungetch(c);
				return 0;
			} else {
				ungetch(d);
				return c;
			}
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;	
}
int getfloat(float *pn)
{
	int c, d, sign;
	double power;

	while (isspace(c = getch()))
		continue;

	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		d = c;
		if (!isdigit(c = getch())) {
			if (c != EOF) {
				ungetch(d);
				ungetch(c);
				return 0;
			} else {
				ungetch(d);
				return c;
			}
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
		power *= 10;
	}
	*pn *= sign / power;
	if (c != EOF)
		ungetch(c);
	return c;		
}
char *strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest)
		++dest;
	while(*dest++ = *src++)
		;
	return result;
}
int strend(const char *str1, const char *str2)
{
	int len1 = 0;
	int len2 = 0;

	while (*str2) {
		++len2;
		++str2;
	}
	while (*str1) {
		++len1;
		++str1;
	}

	while (len1-- && len2--)
		if (*--str1 != *--str2)
			return 0;
	return (++len2) ? 0 : 1;
}
int strend_ver2(const char *s, const char *t)
{
	const char *bs = s;
	const char *bt = t;

	while (*s)
		++s;
	while (*t)
		++t;
	for ( ; *s == *t; --s, --t)
		if (t == bt || s == bs)
			break;
	return (*s == *t && t == bt && *s != '\0') ? 1 : 0;
}
char *strncpy(char *dest, const char *src, size_t n)
{
	char *result = dest;

	while (*src && n--)
		*dest++ = *src++;
	if (n)
		*dest = '\0';
	return result;
}
char *strncat(char *dest, const char *src, size_t n)
{
	char *result = dest;

	while (*dest)
		++dest;
	while (*src && n--)
		*dest++ = *src++;
	if (n)
		*dest = '\0';
	return result;
}
int strncmp(const char *str1, const char *str2, size_t n)
{
	for ( ; *str1 == *str2; ++str1, ++str2)
		if (*str1 == '\0' || --n <= 0)
			return 0;
	return *str1 - *str2;
}
char *reverse(char *s)
{
	int c;
	char *ptr, *result;

	for (ptr = s + (strlen(s)-1), result = s; s < ptr; ++s, --ptr) {
		c = *s;
		*s = *ptr;
		*ptr = c;
	}

	return result;
}
int strindex(char *s, char *t)
{
	char *bs = s;
	char *p, *r;

	for ( ; *s != '\0'; s++) {
		for (p = s, r = t; *r != '\0' && *p == *r; ++p, ++r)
			;
		if (r > t && *r == '\0')
			return s - bs;
	}
	return -1;
}
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
void clearHeap(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		afree(*lineptr++);
}
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
void qsort(char *v[], int left, int right)
{
	int i, last;
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}
int readlines_ver2(char *lineptr[], char *linebuf, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linebuf;
	char *linestop = linebuf + BUF;

	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	return nlines;
}

/***************** Static functions ****************/
static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
static void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("Error: buffer is full");
}
static int getLine(char *line, size_t n)
{
	int c, i;

	i = 0;
	while (--n > 0 && (c = getchar()) != EOF && c != '\n')
		*(line + i++) = c;
	if (c == '\n')
		*(line + i++) = '\n';
	*(line + i) = '\0';

	return i;
}
static char *alloc(size_t n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp -n;
	} else
		return NULL;
}
static void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
static void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
