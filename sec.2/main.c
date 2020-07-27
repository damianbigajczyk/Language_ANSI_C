#include <stdio.h>
#include "exercise_2.h"

int main(void)
{
	char s1[] = {"People celebrate World Environment Day"};
	char s2[] = {"aAdDfFgGjTVY"};

	puts("\n***** Exercise 2.1 *****\n");
	ls_limits();

	puts("\n***** Exercise 2.2 *****\n");
	replaceForLoop();

	puts("\n***** Exercise 2.3 *****\n");
	printf("0xFF is equal to: %d\n", htoi("0xFF"));
	printf("0x1A8B is equal to: %d\n", htoi("1A8B"));
	printf("0x32 is equal to: %d\n", htoi("0032"));
	printf("0xABCD is equal to: %d\n", htoi("0xaBcD"));

	puts("\n***** Exercise 2.4 *****\n");
	printf("Before:\ns1: %s\ns2: %s\n", s1, s2);
	squeeze(s1, s2);
	printf("Result:\ns1: %s\ns2: %s\n", s1, s2);
	
	puts("\n***** Exercise 2.5 *****\n");
	printf("First occurrence: %d\n", any(s1, s2));
	printf("First occurrence: %d\n", any(s1, "W"));
	puts("The number (-1) means haven't found");

	puts("\n***** Exercise 2.6 *****\n");
	printf("%u\n", setbits(18, 4, 3, 81));

	puts("\n***** Exercise 2.7 *****\n");
	printf("%u\n", invert(81, 4, 3));

	puts("\n***** Exercise 2.8 *****\n");
	printf("%d\n", rightrot(128, 138));

	puts("\n***** Exercise 2.9 *****\n");
	printf("%d - Amount of '1' in '2265847'\n", bitcount(2265847));

	puts("\n***** Exercise 2.10 *****\n");
	printf("Before: %s\n", s2);
	lower(s2);
	printf("After: %s\n", s2);

	return 0;
}
