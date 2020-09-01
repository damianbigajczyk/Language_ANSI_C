#include <stdio.h>
#include "exercise_5.h"

int main(void)
{
	int year, month, day;

	day = 28;
	month = 2;
	year = 2004;

	printf("Result: %d\n", day_of_year_ver2(year, month, day));
	printf("Result: %d\n", day_of_year_ver2(-1, 0, 30));
	printf("Result: %d\n", day_of_year_ver2(2008, 12, 31));
	printf("Result: %d\n", day_of_year_ver2(24, 13, 31));
	putchar('\n');
	month_day_ver2(2004, 356, &month, &day);
	printf("Month: %d\tDay: %d\n", month, day);
	month_day_ver2(2004, 366, &month, &day);
	printf("Month: %d\tDay: %d\n", month, day);
	month_day_ver2(-1, 256, &month, &day);
	printf("Month: %d\tDay: %d\n", month, day);
	month_day_ver2(2000, 1, &month, &day);
	printf("Month: %d\tDay: %d\n", month, day);

	return 0;
}
