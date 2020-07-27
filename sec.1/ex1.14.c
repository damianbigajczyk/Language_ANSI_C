#include <stdio.h>
#include <ctype.h>

#define SIGN 128

int main(void)
{
	FILE *pf = fopen("poem", "r");
	int c, i;
	int amount = 0; 
	int count[SIGN] = {0};

	if (!pf) {
		puts("Faile to open file: \"poem\"");
		return -1;
	}
	while ((c = fgetc(pf)) != EOF) {
		count[c]++;
		amount++;
	}
	for (i = 0; i < SIGN; i++)
		if (count[i]) {
			if (isprint(i))
				printf("'%d' - %c - %4.2f%%\n", i, i, (double)count[i]/amount * 100);
			else
				printf("'%d' - %4.2f%%\n", i, (double)count[i]/amount * 100);
		}
	fclose(pf);

	return 0;
}
