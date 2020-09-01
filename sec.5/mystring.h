#ifndef mystring_H_
#define mystring_H_

char *mystrcat(char *dest, const char *src);
char *mystrncat(char *dest, const char *src, size_t n);
char *mystrncpy(char *dest, const char *src, size_t n);
char *reverse(char *s);
int mystrlen(const char *s);
int mystrend(const char *str1, const char *str2);
int mystrend_ver2(const char *s, const char *t);
int mystrcmp(char *str1, char *str2);
int mystrncmp(const char *str1, const char *str2, size_t n);
int strindex(char *s, char *t);

#endif
