#include <stdio.h>
#include <string.h>
#include <math.h>
#include "exercise_4.h"

void mathfunc(char *s);
int main(void)
{
	
	int type;
	double op2;	
	char s[MAX];

	while ((type = getop2(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case NAME:
				mathfunc(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2)
					push(pop() / op2);
				else
					printf("Erroro: zero divisor\n");
				break;
			case '\n':
				printf("Result: %.8g\n", pop());
				break;
			default:
				printf("Unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
void mathfunc(char *s)
{
	double op2;
	
	if (!strcmp("SIN", s))
		push(sin(pop()));
	else if (!strcmp("COS", s))
		push(cos(pop()));
	else if (!strcmp("EXP", s))
		push(exp(pop()));
	else if (!strcmp("POW", s)) {
		op2 = pop();
		push(pow(pop(), op2));
	} else
		printf("Error: %s not supported\n", s);
}
