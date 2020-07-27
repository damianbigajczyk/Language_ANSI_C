#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	int type;
	double op2, temp;
	char s[MAX];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			case 'g':		/* get value */
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;
			case 'd':		/* duplicate */
				op2 = pop();
				push(op2);
				push(op2);
			case 'c':		/* change */
				op2 = pop();
				temp = pop();
				push(op2);
				push(temp);
				break;
			case 'r':		/* clear stack */
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}
