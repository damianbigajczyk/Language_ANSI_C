#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercise_6.h"

#define NKEYS (sizeof(keytab) / sizeof(struct key))

struct key {
	char *word;
	int count;
} keytab[] = {
	{ "auto", 0 },
	{ "break",  0 },
	{ "case", 0 },
	{ "char", 0 },
	{ "const", 0 },
	{ "continue", 0 },
	{ "default", 0 },
	{ "else", 0 },
	{ "unsigned", 0 },
	{ "void", 0 },
	{ "volatile", 0 },
	{ "while", 0 }
};

int binsearch(char *, struct key *, int);
void display(struct key *, int);

int main(void)
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		printf("%s\n", word);
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	}
	display(keytab, NKEYS);

	return 0;
}
int binsearch(char *word, struct key tab[], int n)
{
	int rc, low, mid, high;

	low = 0;
	high = n-1;
	
	while (low <= high) {
		mid = (low+high) / 2;
		if ((rc = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (rc > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}
void display(struct key *keytab, int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d %s\n",
				keytab[i].count, keytab[i].word);
}

