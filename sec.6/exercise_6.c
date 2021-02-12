#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "exercise_6.h"

static char buff[MAXBUF];
static int sp = 0;

static struct nlist *hashtab[HASHSIZE];

static int getch(void)
{
	return (sp > 0) ? buff[--sp] : getchar();
}
static void ungetch(int c)
{
	if (sp == MAXBUF)
		printf("Buffer is full\n");
	else
		buff[sp++] = c;
}
void error(int c, char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n')
		c = getch();
}
void ungets(char *s)
{
	int len = strlen(s);

	while (len > 0)
		ungetch(s[--len]);
}
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;

	while (c == '/') {
	 	if ((c = getch()) == '/') {
		  while ((c = getch()) != '\n')
			;
		} else if (c == '*') {
			while (1)
				if ((c = getch()) == '*') {
					if ((c = getch()) == '/') {
						break;
					} else {
						ungetch(c);
					}
				}
		} else {
			ungetch(c);
			*w = '\0';
			return '/';
		}
		while (isspace(c = getch()))
			;
	}
	if (isalpha(c) || c == '#' || c == '_') {
		for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
		
	} else if (c == '\'' || c == '"') {
		for ( ; --lim > 0; w++)
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF) {
				ungetch(*w);
				break;
			}
	}
	*w = '\0';
	return c;
}
int getword_2(char *w, int lim)
{
	int c = getch();

	if (c == '\n')
		return c;
	while (isspace(c))
		c = getch();
	if (c != EOF)
		*w++ = c;
	if (isalpha(c))
		for ( ; --lim > 0; w++)
			if (!isalpha(*w = getch())) {
				ungetch(*w);
				break;
			}
	*w = '\0';
	return c;
}
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}
Nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (!strcmp(s, np->name))
			return np;
	return NULL;
}
Nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc (sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else 
		free((void *) np->defn);
	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}
void undef(char *s)
{
	struct nlist *prev, *np;
	unsigned hashval;

	prev = NULL;
	hashval = hash(s);

	for (np = hashtab[hashval]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			break;
		prev = np;
	}
	if (np != NULL) {
		if (prev == NULL)
			hashtab[hashval] = np->next;
		else
			prev->next = np->next;
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);
	}
}
void getdef(void)
{
	char name[MAXWORD], def[MAXWORD];
	int i;

	if (!isalpha(getword(name, MAXWORD)))
		error(name[0], "getdef: non-alpha - name expected");
	else {
		for (i = 0; i < MAXWORD-1; i++)
			if ((def[i] = getch()) == EOF || def[i] == '\n')
				break;
		def[i] = '\0';
		if (i <= 0)
			error('\n', "getdef: incomplete define");
		else
			install(name, def);
	}

}
void getundef(void)
{
	char name[MAXWORD];

	if (!isalpha(getword(name, MAXWORD)))
		error(name[0], "getundef: non-alpha in undef");
	else
		undef(name);
}
