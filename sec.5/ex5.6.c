#include <stdio.h>
#include "exercise_5.h"

int main(void)
{
	char name[] = "Damian";

	printf("%s\n", reverse(name));
	printf("%s\n", (strindex("Damian", "an") != -1) ? "found" : "not found");
	printf("%s\n", (strindex("Damian", "wn") != -1) ? "found" : "not found");


	return 0;
}
