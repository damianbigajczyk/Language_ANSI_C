#include <stdio.h>

#define myisupper_2(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0

int myisupper_1(int c);

int main(void)
{
	printf("%d\n", myisupper_1('A'));
	printf("%d\n", myisupper_1('a'));
	printf("%d\n", myisupper_2('a'));
	printf("%d\n", myisupper_2('A'));

	return 0;
}
int myisupper_1(int c)
{
	return (c >= 'A' && c <='Z') ? 1 : 0;
}
