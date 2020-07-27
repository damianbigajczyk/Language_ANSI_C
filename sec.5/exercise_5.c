#include <stdio.h>
#include <ctype.h>
#include "exercise_5.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp;

static int getch(void);
static void ungetch(int c);

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
