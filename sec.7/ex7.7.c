#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 500

enum state {false, true};

_Bool except = false;
_Bool number = false;

void find(FILE *, char *);

int main(int argc, char **argv)
{
	FILE *pf;
	char *pattern;

	while (--argc > 0 && **++argv == '-')
		switch(*++(*argv)) {
			case 'x':
				except = true;
				break;
			case 'n':
				number = true;
				break;
			default:
				break;
			}
	if (argc >= 1) {
		pattern = (char *) malloc(sizeof(*++argv)+1);
		if (!pattern) {
			fprintf(stderr, "Failed to alloc memory\n");
			exit(EXIT_FAILURE);
		}
		strcpy(pattern, *argv);
	} else {
		fprintf(stderr, "Usage: ./%s [-x] [-n] pattern [file...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argc == 1) {
		printf("******* stdin *******\n");
		find(stdin, pattern);
	} else
		while (--argc > 0) {
			if ((pf = fopen(*++argv, "r")) == NULL)
				fprintf(stderr, "Failed to open file: %s\n", *argv);

			printf("******* %s *******\n", *argv);
			find(pf, pattern);
			fclose(pf);
			pf = NULL;
		}

	free(pattern);
	return 0;
}
void find(FILE *pf, char *s)
{
	int nline = 1;
	char line[MAXLINE];

	while (fgets(line, MAXLINE, pf) != NULL) {
		if ((strstr(line, s) != NULL) != except) {
			if (number)
				printf("%d: ", nline++);
			printf("%s", line);
		}
	}
}
