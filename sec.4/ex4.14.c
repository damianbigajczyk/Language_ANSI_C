#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	int x_1 = 5;
	int y_1 = 6;
	double x_2 = 2.564;
	double y_2 = 3.456;

	printf("x_1 = %d\ty_1 = %d\n", x_1, y_1);
	swap(int, x_1, y_1);
	printf("x_1 = %d\ty_1 = %d\n", x_1, y_1);
	print(x_2, y_2);
	swap(double, x_2, y_2);
	print(x_2, y_2);

	return 0;
}
