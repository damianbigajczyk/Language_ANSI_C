#include <stdio.h>

#define MAXPAGE 10
#define MAXLINE 100

void printFile(FILE *, char *);

int main(int argc, char **argv)
{
	FILE *pf;

	while (--argc > 0) {
		if ((pf = fopen(*++argv, "r")) == NULL)
			fprintf(stderr, "Failed to open file: %s\n", *argv);
		else {
			printFile(pf, *argv);
			fclose(pf);
		}
	}
	return 0;
}
void printFile(FILE *pf, char *name)
{
	int page = 0;
	int nline = 1;
	char line[MAXLINE];

	while (fgets(line, MAXLINE, pf) != NULL) {
		if (nline == 1) {
			printf("\n\t\t%s\t\tpage: %d\n", name, ++page);
			printf("%s", line);
			nline++;
		} else {
			if (++nline >= MAXPAGE) {
				printf("%s", line);
				nline = 1;
			} else
				printf("%s", line);
		}
	}	
}
