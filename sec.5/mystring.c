#include <stdio.h>
#include <ctype.h>
#include "mystring.h"

char *mystrcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest)
		++dest;
	while((*dest++ = *src++))
		;
	return result;
}
char *mystrncat(char *dest, const char *src, size_t n)
{
	char *result = dest;

	while (*dest)
		++dest;
	while (*src && n--)
		*dest++ = *src++;
	if (n)
		*dest = '\0';
	return result;
}
char *mystrncpy(char *dest, const char *src, size_t n)
{
	char *result = dest;

	while (*src && n--)
		*dest++ = *src++;
	if (n)
		*dest = '\0';
	return result;
}
char *reverse(char *s)
{
	int c;
	char *ptr, *result;

	for (ptr = s + (mystrlen(s)-1), result = s; s < ptr; ++s, --ptr) {
		c = *s;
		*s = *ptr;
		*ptr = c;
	}

	return result;
}
int mystrlen(const char *s)
{
	int len = 0;
	while (*s++ != '\0')
		++len;
	return len;
}
int mystrend(const char *str1, const char *str2)
{
	int len1 = 0;
	int len2 = 0;

	while (*str2) {
		++len2;
		++str2;
	}
	while (*str1) {
		++len1;
		++str1;
	}

	while (len1-- && len2--)
		if (*--str1 != *--str2)
			return 0;
	return (++len2) ? 0 : 1;
}
int mystrend_ver2(const char *s, const char *t)
{
	const char *bs = s;
	const char *bt = t;

	while (*s)
		++s;
	while (*t)
		++t;
	for ( ; *s == *t; --s, --t)
		if (t == bt || s == bs)
			break;
	return (*s == *t && t == bt && *s != '\0') ? 1 : 0;
}
int mystrcmp(char *str1, char *str2)
{
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2) {
		str1++;
		str2++;
	}
	return (*str1 == *str2) ? 0 : *str1 - *str2;
}
int mystrncmp(const char *str1, const char *str2, size_t n)
{
	for ( ; *str1 == *str2; ++str1, ++str2)
		if (*str1 == '\0' || --n <= 0)
			return 0;
	return *str1 - *str2;
}
int strindex(char *s, char *t)
{
	char *bs = s;
	char *p, *r;

	for ( ; *s != '\0'; s++) {
		for (p = s, r = t; *r != '\0' && *p == *r; ++p, ++r)
			;
		if (r > t && *r == '\0')
			return s - bs;
	}
	return -1;
}
