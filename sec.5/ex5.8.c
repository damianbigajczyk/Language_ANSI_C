#include <stdio.h>
#include <stdint.h>
#include "exercise_5.h"

int main(void)
{
	uint16_t year;
	uint8_t day, month;

	day = 28;
	month = 2;
	year = 2004;

	printf("Result: %d\n", day_of_year(year, month, day));
	printf("Result: %d\n", day_of_year(-1, 0, 30));
	printf("Result: %d\n", day_of_year(2008, 12, 31));
	printf("Result: %d\n", day_of_year(24, 13, 31));
	putchar('\n');
	month_day(2004, 356, &month, &day);
	printf("Month: %hu\tDay: %hu\n", month, day);
	month_day(2004, 366, &month, &day);
	printf("Month: %hu\tDay: %hu\n", month, day);
	month_day(-1, 256, &month, &day);
	printf("Month: %hu\tDay: %hu\n", month, day);
	month_day(2000, 1, &month, &day);
	printf("Month: %hu\tDay: %hu\n", month, day);




	return 0;
}
