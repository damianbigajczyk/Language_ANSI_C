#include <stdio.h>
#include "exercise_4.h"

int main(void)
{
	fprintf(stdout, "%s = %f\n", "123.45", atof("123.45"));
	fprintf(stdout, "%s = %f\n", "-13.45", atof("-13.45"));
	fprintf(stdout, "%s = %f\n", "123.45e5", atof("123.45e5"));
	fprintf(stdout, "%s = %f\n", "-123.45e-3", atof("-123.45e-3"));

	return 0;
}
