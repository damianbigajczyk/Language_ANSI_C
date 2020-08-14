#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "exercise_5.h"

#define BUFSIZE 100
#define ALLOCSIZE 10000
#define TABINC 6
#define YES 1
#define NO 0

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char buf[BUFSIZE];
static int bufp = 0;

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

static int sp = 0;
static double val[MAX];

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
int day_of_year(uint16_t year, uint8_t month, uint16_t day)
{
	int leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (!(year && month && day) || month > 12 || day > daytab[leap][month])
		return -1;
	for (int i = 0; i < month; i++)
		day += daytab[leap][i];
	return day;
}
void month_day(uint16_t year, uint16_t yearday, uint8_t *pmonth, uint8_t *pday)
{
	int i, leap;

	if (!year || !yearday) {
		*pmonth = 0;
		*pday = 0;
		return;
	}
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	if (i > 12 && yearday > daytab[leap][12]) {
		*pmonth = 0;
		*pday = 0;
	} else {
		*pmonth = i;
		*pday = yearday;
	}
}
int day_of_year_ver2(int year, int month, int day)
{
	int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	char *p = daytab[leap];

	if (year <= 0 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
		return -1;
	while (--month)
		day += *++p;
	return day;
}
void month_day_ver2(int year, int yearday, int *pmonth, int *pday)
{
	int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	char *p = daytab[leap];
	int limit = (leap) ? 366: 365;	
	if (year <= 0 || yearday < 1 || yearday > limit) {
		*pmonth = -1;
		*pday = -1;
		return;
	}
	while (yearday > *++p)
		yearday -= *p;
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}
int getop(char *s)
{
	int c;

	while ((*s = c = getch()) == ' ' || c == '\t')
		;
	*(s+1) = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	if (c == '-')
		if (isdigit(c = getch()))
			*++s = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	if (isdigit(c))
		while (isdigit(*++s = c = getch()))
			;
	if (c == '.')
		while (isdigit(*++s = c = getch()))
			;
	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
double atof(char *s)
{
	double val, power;
	int sign;

	for ( ; isspace(*s); ++s)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		++s;
	for (val = 0.0; isdigit(*s); ++s)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; isdigit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
		power *= 10;
	}
	return sign * val / power;
}
void ungets(char *s)
{
	int len = strlen(s);

	while (len > 0)
		ungetch(*(s + --len));
}
void push(double number)
{
	if (sp < MAX)
		val[sp++] = number;
	else
		printf("Error: stack full, can't push %g\n", number);
}
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}
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
int tabpos(int pos, char *s)
{
	return (pos > MAX) ? YES : s[pos];
}
int atoi_2(char *s)
{
	int value = 0;

	while (isdigit(*s))
		value = 10 * value + *s++ - '0';
	return value;
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
		printf("Error: buffer is full\n");
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
