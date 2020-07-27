#include <stdio.h>
#include <time.h>
#include "exercise_3.h"


int main(void)
{
	clock_t start, end;
	double difftime;
	int result;
	int v[] = {1, 3, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 27, 28, 30};
	char s[MAX];
	char t_1[] = {"	sign\nstart		end."};
	char t_2[] = {"\n\n\tstart\t\t\tend."};
	char s_1[] = {"-a-c-e0-9end--"};
	char s_2[MAX];

	puts("\n***** Exercise 3.1 *****\n");
	start = clock();
	binsearch(1, v, sizeof(v)/sizeof(int));
	end = clock();
	difftime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Result: %d\nTime execution: %.8f\n", result, difftime);
	start = clock();
	binsearch_v2(1, v, sizeof(v)/sizeof(int));
	end = clock();
	difftime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Result: %d\nTime execution: %.8f\n", result, difftime);

	puts("\n***** Exercise 3.2 *****\n");
	escape(s, t_1);
	printf("Result: %s\n", s);
	unescape(s, t_2);
	printf("Result: %s\n", s);

	puts("\n***** Exercise 3.3 *****\n");
	start = clock();
	expand(s_1, s_2);
	end = clock();
	difftime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Result: %s\nTime execution: %.8f\n", s_2, difftime);
	for (int i = 0; i < MAX; i++)
		s_2[i] = '\0';
	start = clock();
	expand_v2(s_1, s_2);
	end = clock();
	difftime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Result: %s\nTime execution: %.8f\n", s_2, difftime);

	puts("\n***** Exercise 3.4 *****\n");
	for (int i = 0; i < MAX; i++)
		s[i] = '\0';
	printf("Result: %s\n", itoa(28576, s));
	printf("Result: %s\n", itoa(-123, s));
	printf("Result: %s\n", itoa(0, s));
	
	puts("\n***** Exercise 3.5 *****\n");
	printf("Result: %s\n", itob(-258, s, 2));
	printf("Result: %s\n", itob(-258, s, 8));
	printf("Result: %s\n", itob(-258, s, 16));

	puts("\n***** Exercise 3.6 *****\n");
	printf("Result: %s\n", itoa_v2(28576, s, 10));
	printf("Result: %s\n", itoa_v2(-12345, s, 20));
	printf("Result: %s\n", itoa_v2(0, s, 0));

	return 0;
}
