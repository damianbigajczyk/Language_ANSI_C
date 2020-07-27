#ifndef exercise_3_H_
#define exercise_3_H_
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MAX 30

int binsearch(int x, int v[], int n);
int binsearch_v2(int x, int v[], int n);
void escape(char *s, char *t);
void unescape(char *s, char *t);
char *expand(char *s1, char *s2);
char *expand_v2(char *s1, char *s2);
char *itoa(int n, char *s);
char *itob(int n, char *s, int b);
char *itoa_v2(int n, char *s, int space);

#endif
