#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exercise_6.h"

int main(void)
{
	char string[MAXWORD];	
	struct nlist *ptr;

	while (getword(string, MAXWORD) != EOF)
		if (strcmp(string, "#define") == 0)
			getdef();
		else if (strcmp(string, "#undef") == 0)
			getundef();
		else if (!isalpha(string[0]))
			printf("%s\n", string);
		else if ((ptr = lookup(string)) == NULL)
			printf("%s\n", string);
		else
			ungets(ptr->defn);	
	return 0;
}
