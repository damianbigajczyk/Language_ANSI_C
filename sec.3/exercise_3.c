#include <stdio.h>
#include <string.h>
#include "exercise_3.h"

static void reverse(char *s);

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
int binsearch_v2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = high/2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	return (x == v[mid]) ? mid : -1;
}
void escape(char *s, char *t)
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
	s[j] = '\0';
}
void unescape(char *s, char *t)
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
		switch (t[i]) {
			case '\\':
				switch (t[++i]) {
					case 'n':
						s[j++] = '\n';
						break;
					case 't':
						s[j++] = '\t';
						break;
					default:
						s[j++] = '\\';
						s[j++] = t[i];
						break;
				}
				break;
			default:
				s[j++] = t[i];
				break;
		}
	s[j] = '\0';
}
char *expand(char *s1, char *s2)
{
	int i, j, k;
	for (i = 0, k = 0; s1[i] != '\0'; i++)
		if (s1[i] == '-' && s1[i-1] >= 'A' && s1[i+1] <= 'Z')
			for (j = s1[i-1]+1; j < s1[i+1]; j++, k++)
				s2[k] = j;
		else if (s1[i] == '-' && s1[i-1] >= 'a' && s1[i+1] <= 'z')
			for (j = s1[i-1]+1; j < s1[i+1]; j++, k++)
				s2[k] = j;	
		else if (s1[i] == '-' && s1[i-1] >= '0' && s1[i+1] <= '9')
			for (j = s1[i-1]+1; j < s1[i+1]; j++, k++)
				s2[k] = j;
		else
			s2[k++] = s1[i];
	s2[k] = '\0';
	return s2;
}
char *expand_v2(char *s1, char *s2)
{
	char c;
	int i = 0, j = 0;

	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i+1] >= c) {
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		} else
			s2[j++] = c;
	s2[j] = '\0';
	return s2;
}
char *itoa(int n, char *s)
{
	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return s;
}
char *itob(int n, char *s, int b)
{
	int i, j;
	int sign = n;	
	i = 0;
	
	do {
		j = abs(n % b);
		s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return s;
}
char *itoa_v2(int n, char *s, int space)
{
	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	while (i < space)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
	return s;	
}
static void reverse(char *s)
{
	int i, j, temp;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
