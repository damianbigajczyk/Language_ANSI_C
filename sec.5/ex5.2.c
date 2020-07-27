#include <stdio.h>
#include "exercise_5.h"

int main(void)
{
	int result;
	float value;

	result = getfloat(&value);
	printf("Result: %d\tValue: %.4f\n", result, value); 

	return 0;
}
