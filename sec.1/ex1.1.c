#include <stdio.h>

int main(void)
{
	unsigned int welcome[] = {72, 105, 33, 10, 76, 101, 116, 39, 115, 32, 115, 116, 97, 114, 116,\
			32, 112, 114, 111, 103, 114, 97, 109, 105, 110, 103, 10};
	for (int i = 0; i < sizeof(welcome)/sizeof(unsigned int); i++)
		printf("%c", welcome[i]);

	return 0;
}
