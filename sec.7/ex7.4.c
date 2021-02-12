#include <stdio.h>
#include <stdarg.h>

void miniscanf(char *fmt, ...);

int main(void)
{
	char s[100];
	char c, temp;
	int a;
	float b;

	miniscanf("%d", &a);
	while ((temp = getchar()) != '\n')
		;
	printf("%d\n", a);
	miniscanf("%c", &c);
	while ((temp = getchar()) != '\n')
		;
	printf("%c\n", c);
	miniscanf("%f", &b);
	while ((temp = getchar()) != '\n')
		;
	printf("%f\n", b);
	miniscanf("%s", s);
	while ((temp = getchar()) != '\n')
		;
	printf("%s\n", s);

	return 0;
}
void miniscanf(char *fmt, ...)
{
	va_list ap;
	char *p = fmt, *s, *cval;
	int *ival;
	float *fval;

	va_start(ap, fmt);

	for (p = fmt; *p; ++p) {
		if (*p != '%')
			continue;
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 'f':
				fval = va_arg(ap, float *);
				scanf("%f", fval);
				break;
			case 'c':
				cval = va_arg(ap, char *);
				scanf("%c", cval);
				break;
			case 's':
				s = va_arg(ap, char *);
				scanf("%s", s);
				break;
			default:
				break;
		}

	}
	va_end(ap);
}
