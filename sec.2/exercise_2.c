#include "exercise_2.h"
#include <stdio.h>
#include <limits.h>

static enum boolean {false, true} flag;
static int c, i, j, k;

void ls_limits(void)
{
	printf("The number of bits in a byte %d\n", CHAR_BIT);
	printf("Signed char MIN: %d\t%d\n", SCHAR_MIN, ~(char)((unsigned char) ~0 >> 1));	
	printf("Signed char MAX: %d\t%d\n", SCHAR_MAX, (char)((unsigned char) ~0 >> 1));	
	printf("Unsigned char MAX: %u\t%u\n", UCHAR_MAX, (unsigned char) ~0);	

	printf("short int MIN: %d\t%d\n", SHRT_MIN, ~(short)((unsigned short) ~0 >> 1));
	printf("short int MAX: %d\t%d\n", SHRT_MAX, (short) ((unsigned short) ~0 >> 1));
	printf("unsigned short int MAX: %u\t%u\n", USHRT_MAX, (unsigned short) ~0);

	printf("int MIN: %d\t%d\n", INT_MIN, ~(int)((unsigned int) ~0 >> 1));
	printf("int MAX: %d\t%d\n", INT_MAX, (int)((unsigned int) ~0 >> 1));
	printf("unsigned int MAX: %u\t%u\n", UINT_MAX, (unsigned int) ~0);

	printf("long int MIN: %ld\t%ld\n", LONG_MIN, ~(long)((unsigned long) ~0 >> 1));
	printf("long int MAX: %ld\t%ld\n", LONG_MAX, (long)((unsigned long) ~0 >> 1));
	printf("unsigned long int MAX: %lu\t%lu\n", ULONG_MAX, (unsigned long) ~0);
}
void replaceForLoop(void)
{
	char s[LIM] = {0};
	flag = true;	
	i = 0;

	puts("Enter any text you want:");
	while (flag) {
		if (i >= LIM-1)
			flag = false;
		else if ((c = getchar()) == '\n')
			flag = false;
		else if (c == EOF)
			flag = false;
		else {
			s[i] = c;
			++i;
		}
	}
	while (getchar() != '\n')
		continue;
	for (i = 0; i < LIM; i++)
		printf("%c\t", s[i]);
	putchar('\n');
}
int htoi(char *s)
{
	int n = 0;
	int hexdigit;
	i = 0;
	flag = true;

	if (s[i] == '0') {
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	for ( ; flag; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			flag = false;
		if (flag)
			n = 16 * n + hexdigit;
	}
	return n;

}
void squeeze(char *s1, char *s2)
{	
	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
		       ;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}	
	s1[k] = '\0';
}
int any(char *s1, char *s2)
{
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s2[j] == s1[i])
				return i;
	return -1;
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask_x = ~(~(~0 << n) << (p+1-n));
	unsigned mask_y = ~(~0 << n);
	x &= mask_x;
	y &= mask_y;
	y <<= (p+1-n);
	return x | y;
}
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p+1-n));
}
int rightrot(int x, int n)
{
	i = 8 * sizeof(int);
	i %= n;
	unsigned mask = x & ~(~0 << n);
	mask <<= (8 * sizeof(int) - n);
	x >>= n;
	return x | mask;
}
int bitcount(unsigned x)
{
	for (i = 0; x ; x &= x-1)
		i++;
	return i;
}
void lower(char *s)
{
	while (*s != '\0') {
		*s += (*s >= 'A' && *s <= 'Z') ? 'a' - 'A' : 0;
		s++;
	}
}
