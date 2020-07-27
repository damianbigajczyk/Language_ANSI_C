#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

void ungets(char *s);
int getch(void);
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
	char s[] = "Sophisticated";	
	int c;

	ungets(s);
	while ((c = getch()) != '\n')
		putchar(c);
	putchar('\n');

	return 0;
}
void ungets(char *s)
{
	int len = strlen(s);

	while (len > 0)
		ungetch(s[--len]);
}
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
