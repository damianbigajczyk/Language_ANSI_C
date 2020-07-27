#include <stdio.h>

#define BUFSIZE 10

int getch(void);
void ungetch(int c);
int menu(void);
void clear(void);

int buf[BUFSIZE];
int bufp = 0;

int main(void)
{
	int c, choice;

	choice = menu();

	while (choice > 0 && choice < 3) {
		switch (choice) {
			case 1:
				c = getch();
				printf("Result: %c\n", c);
				break;
			case 2:
				ungetch(c);
				break;
			default:
				puts("Error");
				break;
		}
		choice = menu();
	}

	return 0;
}
int getch(void)
{
	if (bufp > 0)
		return buf[--bufp];
	else {
		fputs("Please, enter a sign: ", stdout);	
		int c = getchar();
		clear();
		return c;
	}
}
void ungetch(int c)
{
	if (bufp > BUFSIZE)
		printf("ungetch: too many characters\n");
	else {
		buf[bufp++] = c;
		printf("Add to buf: %c\n", c);
	}
}
int menu(void)
{
	int rc;

	puts("Choose function:\n1) getch()\t2)ungetch()\t3)Exit");
	while ((rc = getchar()) != '1' && rc != '2' && rc != '3') {
		puts("Wrong input, try again!");
		clear();
	}
	clear();
	return rc - '0';
}
void clear(void)
{
	while (getchar() != '\n') {}
}
