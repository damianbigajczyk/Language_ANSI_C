#ifndef exercise_4_H_
#define exercise_4_H_

#define MAX 100
#define NUMBER '0'
#define NAME 'n'
#define BUFSIZE 100
#define ABS(x) (((x) < 0 ) ? -(x) : (x))
#define swap(t, x, y) { t temp; \
			temp = x; \
			x = y; \
			y = temp; }
#define print(x, y) printf(#x " = %.4f\t" #y " = %.4f\n", x, y)

int getLine(FILE *pf, char *line, int max);
int strindex(char s[], char t[]);
double atof(char *s);
int getop(char *s);
int getop2(char *s);
int getop3(char *s);
void push(double number);
double pop(void);
void clear(void);
int getop_4(char *s);
void itoa(int a);
void reverse(char *s);

#endif
