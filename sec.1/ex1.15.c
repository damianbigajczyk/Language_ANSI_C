#include <stdio.h>

double convertToFahr(double temp);

int main(void)
{
	double temp[] = {0.0, 5.9, 15.3, 23.3, 30.5};

	for (int i = 0; i < sizeof(temp)/sizeof(double); i++)
		printf("%5.2fC = %5.2fF\n", temp[i], convertToFahr(*(temp + i)));

	return 0;
}

double convertToFahr(double temp)
{
	return 9.0/5.0 * temp + 32;
}
