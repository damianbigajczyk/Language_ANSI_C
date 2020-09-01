#include <stdio.h>
#include "mystring.h"

int main(void)
{
	char str1[10];
	char *str2 = "Dam";
	char *str3 = "ian";
	char *str4 = "Damian";
	char *str5 = "DamIan";

	printf("Result: %s\n", mystrncpy(str1, str2, 4));
	printf("Result: %s\n", mystrncat(str1, str3, 4));
	printf("Result: %d\n", mystrncmp(str1, str4, 6));
	printf("Result: %d\n", mystrncmp(str1, str5, 20));

	return 0;
}
