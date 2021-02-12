#include <stdio.h>
#include <stdarg.h>

void miniprintf(char *fmt, ...);

int main(void)
{
	miniprintf("Sign: %c\n", 'A');
	miniprintf("Val: %d\n", 50);
	miniprintf("Val: %f\n", 12.258);
	miniprintf("Val: %s\n", "Test has finished succesfully.");
	return 0;
}

void miniprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int c, ival;
	double dval;

	va_start(ap, fmt);

	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
			case 'c':
				c = va_arg(ap, int);
				putchar(c);
				break;
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
