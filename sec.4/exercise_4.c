#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exercise_4.h"

static int getch(void);
static void ungetch(int c);
static int getLine_2(char *line, int max);

static int sp = 0;		/*next free stack position*/
static double val[MAX];
static char buf[BUFSIZE];
static int bufp;
static char line[MAX];
static int j;


int getLine(FILE *pf, char *line, int max)
{
	int c, i;

	i = 0;
	while (--max > 0 && (c = fgetc(pf)) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
int strindex(char s[], char t[])
{
	int i, j, k, pos;

	pos = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}
double atof(char *s)
{
	double val, power;
	int i, sign, exp;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;

	if (s[i] == 'E' || s[i] == 'e') {
		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if (sign == 1)
			while (exp-- > 0)
				val *= 10;
		else
			while (exp-- > 0)
				val /= 10;
	}

	return val;
}
int getop(char *s)
{
	int i, c;

	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '-' && c != '.')
		return c;
	if (c == '-')
		if (isdigit(c = getch()))
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) {}
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) {}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
int getop2(char *s)
{
	int c, i;

	i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		continue;
	s[1] = '\0';
	if (isalpha(c)) {
		s[0] = toupper(c);
		while (isalpha(c = getch()))
			s[++i] = toupper(c);
		s[++i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) > 1)
			return NAME;
		else {
			ungetch(c);
			return s[0];
		}
	}
	if (!isdigit(c) && c != '-' && c != '.')
		return c;
	if (c == '-')
		if (isdigit(c = getch()))
			s[++i] = c;
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) {}
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) {}
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
int getop3(char *s)
{
	int c, i;

	i = 0;
	if (line[j] == '\0')
		if (getLine_2(line, MAX) == 0)
			return EOF;
		else
			j = 0;
	while ((s[0] = c = line[j++]) == ' ' || c == '\t')
		continue;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[j++]))
			continue;
	if (c == '.')
		while (isdigit(s[++i] = c = line[j++]))
			continue;
	s[i] = '\0';
	j--;
	return NUMBER;
}
int getop_4(char *s)
{
	int i, c;
	static int prevC = 0;

	i = 0;
	if (prevC == 0)
		c = getch();
	else {
		c = prevC;
		prevC = 0;
	}

	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '-' && c != '.')
		return c;
	if (c == '-')
		if (isdigit(c = getch()))
			s[++i] = c;
		else {
			if (c != EOF)
				prevC = c;
			return '-';
		}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) {}
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) {}
	s[i] = '\0';
	if (c != EOF)
		prevC = c;
	return NUMBER;
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
void clear(void)
{
	sp = 0;
}
void itoa(int a)
{
	if (ABS(a / 10))	
		itoa(ABS(a / 10));
	putchar(ABS(a % 10) + '0');
}
void reverse(char *s)
{
	int c = *s;
	if (*s != '\0')
		reverse(++s);
	putchar(c);
}

static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
static void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
static int getLine_2(char *line, int max)
{
	int c, i;

	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
