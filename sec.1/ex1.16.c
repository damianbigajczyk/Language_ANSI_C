#include <stdio.h>

#define MAX 1000

int getLine(char *line, int maxline, FILE *pf);
void cpyLine(char *destiny, char *source);

int main(void)
{
	FILE *pf = fopen("poem", "r");
	int len, n = 0, max = 0;
	char line[MAX], longest[MAX];

	if (!pf) {
		puts("Failed to open file \"poem\"");
		return -1;
	}
	while ((len = getLine(line, MAX, pf)) > 0) {
		printf("%d (%d) %s", ++n, len, line);
		if (len > max) {
			cpyLine(longest, line);
			max = len;
		}
	}
	printf("\nThe longest row: %s\nLength: %d\n", longest, max);
	fclose(pf);

	return 0;
}
int getLine(char *line, int maxline, FILE *pf)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = fgetc(pf)) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n') 
		line[i++] = c;
	line[i] = '\0';
	return i;
}
void cpyLine(char *destiny, char *source)
{
	int i = 0;
	while ((destiny[i] = source[i]) != '\0')
		++i;
}
