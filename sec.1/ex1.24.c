#include <stdio.h>

int check[] = {0, 0, 0};

void in_quote(int c, FILE *pf);
void in_comment(FILE *pf);
void search(int c, FILE *pf);

int main(void)
{
	FILE *pf = fopen("code", "r");
	int c;
	extern int check[];

	if (!pf) {
		puts("Failed to open file: \"code\"");
		return -1;
	}
	while ((c = fgetc(pf)) != EOF) {
		if (c == '/') {
			if ((c = fgetc(pf)) == '*') {
				in_comment(pf);
			} else if (c == '/') {
				while ((c = fgetc(pf)) != '\n')
					continue;
			} else {
				search(c, pf);
			}
		} else if (c == '\'' || c == '"')
			in_quote(c, pf);
		else
			search(c, pf);
	}
	fclose(pf);
	if (check[0] != 0)
		printf("Unbalanced braces: %s\n", (check[0] < 0) ? "Lack of" : "To many");
	else if (check[1] != 0)
		printf("Unbalanced brackets: %s\n", (check[1] < 0) ? "Lack of" : "To many");
	if (check[2] != 0)
		printf("Unbalanced parenthses: %s\n", (check[2] < 0) ? "Lack of" : "To many");

	return 0;
}
void in_quote(int c, FILE *pf)
{
	int d;

	while ((d = fgetc(pf)) != c)
		continue;
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
void search(int c, FILE *pf)
{
	extern int check[];
	switch (c) {
		case '{':
			check[0]++;
			break;
		case '[':
			check[1]++;
			break;
		case '(':
			check[2]++;
			break;
		case '}':
			check[0]--;
			break;
		case ']':
			check[1]--;
			break;
		case ')':
			check[2]--;
			break;
		default:
			break;
	}
}
