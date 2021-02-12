#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIM 50
#define MAXBUF 10

static char buff[MAXBUF];
static int sp = 0;

static int getch(void)
{
	return (sp > 0) ? buff[--sp] : getchar();
}
static void ungetch(int c)
{
	if (sp == MAXBUF)
		printf("Buffer is full\n");
	else
		buff[sp++] = c;
}

char *getSentence(char *s, int lim);

int main(int argc, char **argv)
{
	int n = (argc > 1) ? atoi(argv[1]) : LIM;
	char s[n];

	while (getSentence(s, n))
		printf("%s\n", s);
	return 0;
}
char *getSentence(char *s, int lim)
{
	int c;
	char *ptr = s;
	char temp[5];

	while (--lim && (c = getch()) != EOF) {
		if (isspace(c)) {
			*s++ = '\\';
			sprintf(temp, "0x%X", c);
			for (int i = strlen(temp)-1; i >= 0; --i)
				ungetch(temp[i]);
		 } else
			*s++ = c;
	}
	*s = '\0';
	return (ptr == s) ? NULL : ptr;
}
