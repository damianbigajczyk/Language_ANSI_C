#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	int type;
	double op2;	
	char s[MAX];

	while ((type = getop3(s)) != EOF) {
		switch (type) {
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
