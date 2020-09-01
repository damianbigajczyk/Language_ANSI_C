#include <ctype.h>
#include "myctype.h"

int atoi_2(char *s)
{
	int value = 0;

	while (isdigit(*s))
		value = 10 * value + *s++ - '0';
	return value;
}
double atof(char *s)
{
	double val, power;
	int sign;

	for ( ; isspace(*s); ++s)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		++s;
	for (val = 0.0; isdigit(*s); ++s)
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		++s;
	for (power = 1.0; isdigit(*s); ++s) {
		val = 10.0 * val + (*s - '0');
		power *= 10;
	}
	return sign * val / power;
}

