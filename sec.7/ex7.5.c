#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXOP 20
#define NUMBER '0'

double val[MAXVAL];
int sp = 0;

int getop(char *);
void push(double);
double pop(void);

int main(void)
{
	int type;
	char s[MAXOP];
	double temp;

	while ((type = getop(s)) != EOF)
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				temp = pop();
				push(pop() - temp);
				break;
			case '/':
				temp = pop();
				if (temp != 0.0)
					push(pop() / temp);
				else
					fprintf(stderr, "error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				fprintf(stderr, "error: unknown command %s\n", s);
				break;
		}		
	return 0;
}
int getop(char *s)
{
	char c;
	int rc;
	double value;

	while ((rc = scanf("%c", &c)) != EOF)
		if ((*s++ = c) != ' ' && c != '\t')
		       break;
	*s = '\0';
	if (rc == EOF)
		return EOF;
	else if (!isdigit(c) && c != '.')
		return c;
	ungetc(c, stdin);
	scanf("%lf", &value);
	sscanf(s, "%lf", &value);
	return NUMBER;
}
void push(double value)
{
	if (sp < MAXVAL)
		val[sp++] = value;
	else
		fprintf(stderr, "Stack if full\n");
}
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		fprintf(stderr, "Stack is empty\n");
		return 0.0;
	}
}
