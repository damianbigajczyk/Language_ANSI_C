#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 100
#define MAXLEN 1000
#define DEFAULT 10

int getLine(char *line, int max);
int atoi_3(char *s);

int main(int argc, char **argv)
{
	char line[MAXLEN];
	int len, n, nlines, first, last;
	nlines = 0;
	last = 0;

	if (argc == 1)
		n = DEFAULT;
	else if (argc == 2 && (**(argv+1) == '-')) {
		n = atoi_3(*(argv+1)+1);
		if (n < 1 || n > MAXLINE)
			n = MAXLINE;
	} else { 
		fprintf(stderr, "Usage: %s [-n]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char **lineptr = (char **)calloc(n, sizeof(char *));
	if (!lineptr) {
		fprintf(stderr, "Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while ((len = getLine(line, MAXLEN)) > 0) {
		char *ptr = (char *)calloc(len+1, sizeof(char));
		if (!ptr) {
			fprintf(stderr, "Failed to allocate mamory\n");
			break;
		}
		strcpy(ptr, line);
		if (lineptr[last])
			free(lineptr[last]);
		lineptr[last++] = ptr;
		last %= n;
		++nlines;
	}
	first = (n > nlines) ? last-n : nlines % n;
	for (int i = first, temp = n; temp-- > 0; i = (i+1)% n) {
		printf("%s", lineptr[i]);
		free(lineptr[i]);
	}
	free(lineptr);

	return 0;
}
int getLine(char *line, int max)
{
	int c, i;

	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		*(line + i++) = c;
	if (c == '\n')
		*(line + i++) = c;
	*(line + i) = '\0';

	return i;
}
int atoi_3(char *s)
{
	int value = 0;

	while (isdigit(*s))
		value = 10 * value + *s++ - '0';
	return value;
}
