#include <stdio.h>

int main(void)
{
	enum state {false, true} flag;
	char c;
	puts("Input your text or press '#' to end");
	while((c = getchar()) != '#') {
		if (c == ' ' && !flag) {
			putchar(c);
			flag = true;
		} else if (c == ' ' && flag)
			continue;
		else {
			putchar(c);
			flag = false;
		}
	}

	return 0;
}
