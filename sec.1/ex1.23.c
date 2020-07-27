#include <stdio.h>

void rmComment(int c, FILE *pf);
void in_comment(FILE *pf);
void echo_quote(int c, FILE *pf);

int main(void)
{
	FILE *pf = fopen("code", "r");
	int c;
	if (!pf) {
		puts("Failed to open file: \"code\"");
		return -1;
	}
	while ((c = fgetc(pf)) != EOF)
		rmComment(c, pf);
	fclose(pf);

	return 0;
}

void rmComment(int c, FILE *pf)
{
	int d;

	if (c == '/') {
		if ((d = fgetc(pf)) == '*') {
			in_comment(pf);
		} else if (d == '/') {
			while ((d = fgetc(pf)) != '\n')
				continue;
			putchar(d);
		} else {
			putchar(c);
			putchar(d);
		}

	} else if (c == '\'' || c == '"')
		echo_quote(c, pf);
	else
		putchar(c);		
}
void in_comment(FILE *pf)
{
	int prev = fgetc(pf);
	int next = fgetc(pf);
	while (prev != '*' || next != '/') {
		prev = next;
		next = fgetc(pf);
	}
}
void echo_quote(int c, FILE *pf)
{
	int d;

	putchar(c);
	while ((d = fgetc(pf)) != c)
		putchar(d);
	putchar(d);
}
