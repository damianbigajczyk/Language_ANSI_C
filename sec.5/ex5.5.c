#include <stdio.h>
#include "exercise_5.h"

int main(void)
{
	char str1[10];
	char *str2 = "Dam";
	char *str3 = "ian";
	char *str4 = "Damian";
	char *str5 = "DamIan";

	printf("Result: %s\n", strncpy(str1, str2, 4));
	printf("Result: %s\n", strncat(str1, str3, 4));
	printf("Result: %d\n", strncmp(str1, str4, 6));
	printf("Result: %d\n", strncmp(str1, str5, 20));

	return 0;
}
