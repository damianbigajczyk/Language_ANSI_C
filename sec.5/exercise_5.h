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
double atof(char *s);
int atoi_2(char *s);

char *reverse(char *s);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
int strend(const char *str1, const char *str2);
int strend_ver2(const char *s, const char *t);
int strcmp_2(char *str1, char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
int strindex(char *s, char *t);
int charcmp(char *s1, char *s2);

int readlines(char *lineptr[], int nlines);
int readlines_ver2(char *lineptr[], char *linebuf, int nlines);
void writelines(char *lineptr[], int nlines);
void writelines_2(char *lineptr[], int nlines, int dec);
void clearHeap(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
void qsort_2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int day_of_year(__uint16_t year, __uint8_t month, __uint16_t day);
void month_day(__uint16_t year, __uint16_t yearday, __uint8_t *pmonth, __uint8_t *pday);
int day_of_year_ver2(int year, int month, int day);
void month_day_ver2(int year, int yearday, int *pmonth, int *pday);

void ungets(char *s);
void push(double number);
double pop(void);

void settab(int argc, char **argv, char *s);
void esettab(int argc, char **argv, char *s);
void entab(char *s);
void detab(char *s);
int tabpos(int pos, char *s);

#endif
