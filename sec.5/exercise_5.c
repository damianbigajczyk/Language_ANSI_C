#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "exercise_5.h"
#include "stack.h"
#include "myctype.h"

#define BUFSIZE 100

extern char *alloc(size_t n);
extern void afree(char *p);
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char buf[BUFSIZE];
static int bufp = 0;
static int sp = 0;
static double val[MAX];

static int getch(void);
static void ungetch(int c);
static int getLine(char *line, size_t n);

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
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
void writelines_2(char *lineptr[], int nlines, int dec)
{
	if (dec)
		while (nlines--)
			printf("%s\n", lineptr[nlines]);
	else
		while (nlines--)
			printf("%s\n", *lineptr++);
}
int day_of_year(uint16_t year, uint8_t month, uint16_t day)
{
	int leap;

	leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
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
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
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
	int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	char *p = daytab[leap];

	if (year <= 0 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
		return -1;
	while (--month)
		day += *++p;
	return day;
}
void month_day_ver2(int year, int yearday, int *pmonth, int *pday)
{
	int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
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
	if (c == '-') {
		if (isdigit(c = getch()))
			*++s = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
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
void clearStack(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		afree(*lineptr++);
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
