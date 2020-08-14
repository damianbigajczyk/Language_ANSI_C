#include <stdio.h>
#include "exercise_5.h"

int main(int argc, char **argv)
{
	char s[MAXOP];	
	double op2;

	if (argc < 2) {
		printf("Usage: %s [expression]\n", argv[0]);
		return 1;
	}

	while(--argc > 0) {
		ungets(" ");
		ungets(*++argv);
		switch(getop(s)) {
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
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2)
					push(pop() / op2);
				else
					printf( "error: zero divisor\n");
				break;
			default:
				printf("error: unknown command %s\n", s);
				argc = 1;
				break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}
