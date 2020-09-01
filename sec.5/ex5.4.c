#include <stdio.h>
#include <time.h>
#include "mystring.h"

void test_func(char *str1, char *str2, int (*pfun) (const char *s, const char *t));

int main(void)
{
	char *str1 = "Damian";
	char *str2 = "an";
	char *str3 = "smian";
	char *str4 = "asfdsafdsafdsafdsafdsfdaDamian";
	
	test_func(str1, str2, mystrend);
	test_func(str1, str2, mystrend_ver2);

	test_func(str1, str3, mystrend);
	test_func(str1, str3, mystrend_ver2);

	test_func(str1, str4, mystrend);
	test_func(str1, str4, mystrend_ver2);


	return 0;
}
void test_func(char *str1, char *str2, int (*pfun) (const char *s, const char *t))
{
	clock_t start, end;
	double time_taken;

	start = clock();
	printf("%s\n", pfun(str1, str2) ? "found" : "not found");
	end = clock();
	time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	printf("Time execution: %.6f\n", time_taken);
}
