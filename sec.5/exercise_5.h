#ifndef exercise_5_H_
#define exercise_5_H_

#define MAXSTOR 5000
#define MAXLEN 1000
#define BUF 5000
#define MAXOP 100
#define NUMBER '0'
#define MAX 100

int getint(int *pn);
int getfloat(float *pn);
int getop(char *s);

int readlines(char *lineptr[], int nlines);
int readlines_ver2(char *lineptr[], char *linebuf, int nlines);
void writelines(char *lineptr[], int nlines);
void writelines_2(char *lineptr[], int nlines, int dec);
void clearStack(char *lineptr[], int nlines);

int day_of_year(__uint16_t year, __uint8_t month, __uint16_t day);
void month_day(__uint16_t year, __uint16_t yearday, __uint8_t *pmonth, __uint8_t *pday);
int day_of_year_ver2(int year, int month, int day);
void month_day_ver2(int year, int yearday, int *pmonth, int *pday);

void ungets(char *s);
void push(double number);
double pop(void);

#endif
