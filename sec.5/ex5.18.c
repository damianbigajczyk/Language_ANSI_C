#include <stdio.h>
#include <string.h>
#include "dcl.h"

extern int tokentype;
extern int prevtoken;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

int main(void)
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s \n", name, out, datatype);
	}

	return 0;
}

