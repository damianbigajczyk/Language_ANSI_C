#include <stdio.h>

#define TAB 6

int main(void)
{	
	int c;
	int nb = 0, nt = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			nb++;
			if (nb % TAB == 0) {
				nt++;
				nb = 0;
			}
		} else {
			while(nt) {
				putchar('\t');
				nt--;
			}
			while(nb) {
				putchar(' ');
				nb--;
			}
			putchar(c);
		}
	}

	return 0;
}
