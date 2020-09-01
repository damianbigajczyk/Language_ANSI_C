#ifndef sort_H_
#define sort_H_

void qsort_1(char *lineptr[], int left, int right);
void qsort_2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

#endif
