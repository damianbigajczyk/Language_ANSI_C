#include <stdio.h>

#define LEN 13

int main(void)
{
	FILE *pf = fopen("poem", "r");
	int length[LEN] = {0};
	int count = 0;
	int c, i, j;

	if (!pf) {
		puts("Faile to open file: \"poem\"");
		return -1;
	}
	while ((c = fgetc(pf)) != EOF) {
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			count++;
		else {
			if (count < LEN)
				(*(length + count))++;
			else
				length[0]++; //overflow
			count = 0;
		}
	}
	fclose(pf);
	puts("Length - horizonatally");
	for (i = 1; i < LEN; i++) {
		printf("%2d|", i);
		for (j = 0; j < length[i]; j++)
			putchar('-');
		printf("\t(%d)\n", length[i]);
	}

	puts("\nLength - vertically");
	for (i = 1; i < LEN; i++)
		printf("%2d ", i);
	putchar('\n');
	for (i = 1; i < LEN; i++)
		printf("___");
	putchar('\n');
	for (i = 1; i < LEN; i++) {
		for (j = 1; j < LEN; j++)
			if (length[j]  >= i)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}

	puts("\nLength - vertically");
	for (i = LEN; i > 0; i--) {
		for (j = 1; j < LEN; j++)
			if (length[j]  >= i)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}
	for (i = 1; i < LEN; i++)
		printf("___");
	putchar('\n');
	for (i = 1; i < LEN; i++)
		printf("%2d ", i);
	putchar('\n');

	return 0;
}
