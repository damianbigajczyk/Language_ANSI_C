#include <stdio.h>

#define MAX 1000

int getLine(char *line, int maxline, FILE *pf);

int main(void)
{
	FILE *pf = fopen("poem", "r");
	int len, n = 1;
	char line[MAX];

	if (!pf) {
		puts("Failed to open file \"poem\"");
		return -1;
	}
	while ((len = getLine(line, MAX, pf)) > 0)
		if (len > 1)
			printf("%d (%d) %s", n++, len, line);
		else
			putchar('\n');
	fclose(pf);
	return 0;
}
int getLine(char *line, int maxline, FILE *pf)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = fgetc(pf)) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') {
		if (i != 0) {
			while (line[--i] == ' ' || line[i] == '\t')
				line[i] = '\0';
			i++;
		}
		line[i++] = c;
	}
	line[i] = '\0';
	return i;	
}
