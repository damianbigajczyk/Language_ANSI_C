#include <stdio.h>

#define MAX 25
#define TAB 6

int getLine(char *s, int n, FILE *pf);
void check(char *s);
void printLine(char *s);

int main(void)
{
	FILE *pf = fopen("poem", "r");
	char display[MAX];

	if (!pf) {
		puts("Failed to open file \"poem\"");
		return -1;
	}
	while (getLine(display, MAX, pf) > 0) {
		check(display);
		printLine(display);
	}
	fclose(pf);

	return 0;
}

int getLine(char *s, int n, FILE *pf)
{
	int len = 0;
	while (--n > 0 && (*s = fgetc(pf)) != EOF) {
		if (*s == '\t')
			for (int i = 0; i < TAB; i++) {
				*(s++) = ' ';
				len++;
				if (!(--n)) {
					--len;
					break;
				}	
			}
		s++;
		len++;
	}

	*s = '\0';
	return len;
}
void check(char *s)
{
	for (int i = 0; i < MAX - 1; i++)
		if (*(s + i) == '\n')
			*(s + i) = ' ';
	for (int i = 2; *(s + MAX - i) == ' '; i++)
		*(s + MAX - i) = '\0';
}
void printLine(char *s)
{
	int i = (*s == ' ')? 1 : 0;
	for (; *(s + i) != '\0'; i++)
		putchar(*(s + i));
	putchar('\n');
}
