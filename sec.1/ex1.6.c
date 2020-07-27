#include <stdio.h>

int main(void)
{
	puts("Press [enter], please:");
	printf("The value of ( getchar() != EOF ) is equal to: %d\n",
			getchar() != EOF);

	return 0;
}
