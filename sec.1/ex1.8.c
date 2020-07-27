#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	bool flag = false;
	char c;
	int space = 0;
	int tab = 0;
	int enter = 0;
	int other = 0;

	puts("Enter your text, to end press [enter]");
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			flag = false;
			space++;
		} else if (c == '\t') {
			flag = false;
			tab++;
		} else if (c == '\n') {
			if (flag)
				break;
			enter++;
			flag = true;
		} else {
			flag = false;
			other++;
		}
	}
	printf("Space = %d\n\\t = %d\n\\n = %d\nothers = %d\n", space, tab, enter, other); 

	return 0;
}
