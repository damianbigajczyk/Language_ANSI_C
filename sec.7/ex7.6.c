#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 500
int main(int argc, char *argv[])
{
	FILE *pf_1, *pf_2;
	char s1[MAXLINE], s2[MAXLINE];
	char *lp1, *lp2;

	if (argc < 3) {
		fprintf(stderr, "Usage: ./%s file_1 file_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((pf_1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Failed to open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((pf_2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "Failed to open file: %s\n", argv[2]);
		fclose(pf_1);
		exit(EXIT_FAILURE);
	}
	do {
		lp1 = fgets(s1, MAXLINE, pf_1);
		lp2 = fgets(s2, MAXLINE, pf_2);
		if (lp1 == s1 && lp2 == s2) {
			if (strcmp(s1, s2) != 0) {
				printf("S1: %s\nS2: %s\n", s1, s2);
				lp1 = lp2 = NULL;
			}
		} else if (lp1 != s1 && lp2 == s2)
			printf("EOF file 1: %s\n", s1);
		else if (lp1 == s1 && lp2 != s2)
			printf("EOF file 2: %s\n", s2);
	} while (lp1 == s1 && lp2 == s2);
	fclose(pf_1);
	fclose(pf_2);

	return 0;
}
