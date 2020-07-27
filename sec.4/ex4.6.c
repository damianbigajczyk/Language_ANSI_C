#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	int type, var;
	double op2, v;
	char s[MAX];
	double variable[26];
	for (int i = 0; i < 26; i++)
		variable[i] = 0.0;

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
			case '=':
				pop();
				if (var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("Error: no variable name\n");
				break;
			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if (type == 'v')
					push(v);
				else
					printf("Error: unknown command %s\n", s);
				break;
		}
		var = type;
	}

	return 0;
}
