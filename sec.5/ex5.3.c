#include <stdio.h>
#include "mystring.h"

int main(void)
{
	char fullname[20] = "Damian ";
	char add[] = "Bigajczyk";

	printf("%s\n", mystrcat(fullname, add));

	return 0;
}
