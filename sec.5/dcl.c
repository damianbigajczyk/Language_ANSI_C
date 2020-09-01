#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"

static int getch(void);
static void ungetch(int c);
static char buf[BUFSIZE];
static int bufp = 0;

int tokentype;
int prevtoken = NO;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void)
{
	int c;
	char *p = token;

	if (prevtoken) {
		prevtoken = NO;
		return tokentype;
	}
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}
void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}
void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')') {
			printf("error: missing )\n");
			prevtoken = YES;
		}
	} else if (tokentype == NAME)
		strcpy(name, token);
	else {
		printf("error: expected name or (dcl)\n");
		prevtoken = YES;
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
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
