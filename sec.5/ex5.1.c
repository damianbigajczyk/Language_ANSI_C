#include <stdio.h>
#include "exercise_5.h"

int main(void)
{
	int value, result;

	result = getint(&value);
	printf("Result: %d\tValue: %d\n", result, value); 

	return 0;
}
