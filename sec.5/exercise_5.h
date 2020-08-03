#ifndef exercise_5_H_
#define exercise_5_H_

#define MAXSTOR 5000
#define MAXLEN 1000
#define BUF 5000

int getint(int *pn);
int getfloat(float *pn);
char *strcat(char *dest, const char *src);
int strend(const char *str1, const char *str2);
int strend_ver2(const char *s, const char *t);
char *strncpy(char *dest, const char *src, size_t n);
char *strncat(char *dest, const char *src, size_t n);
int strncmp(const char *str1, const char *str2, size_t n);
char *reverse(char *s);
int strindex(char *s, char *t);
int readlines(char *lineptr[], int nlines);
void clearHeap(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int readlines_ver2(char *lineptr[], char *linebuf, int nlines);
int day_of_year(__uint16_t year, __uint8_t month, __uint16_t day);
void month_day(__uint16_t year, __uint16_t yearday, __uint8_t *pmonth, __uint8_t *pday);
int day_of_year_ver2(int year, int month, int day);
void month_day_ver2(int year, int yearday, int *pmonth, int *pday);

#endif
