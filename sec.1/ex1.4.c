#include <stdio.h>

int main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	celsius = lower;
	while (celsius <= upper) {
		fahr = 9.0/5.0 * celsius + 32;
		printf("%6.2fC = %6.2fF\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}
