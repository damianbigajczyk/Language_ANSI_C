#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	itoa(123);
	putchar('\n');
	itoa(-123);
	putchar('\n');
	itoa(-2147483648);
	putchar('\n');
	itoa(0);
	putchar('\n');

	return 0;
}
