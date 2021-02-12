#ifndef exercise_6_H_
#define exercise_6_H_

#define MAXWORD 100
#define MAXBUF 10
#define HASHSIZE 101

typedef struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
}Nlist;

int getword(char *, int);
int getword_2(char *word, int lim);

unsigned hash(char *s);
Nlist *lookup(char *s);
Nlist *install(char *name, char *defn);
void undef(char *s);
void ungets(char *s);
void error(int c, char *s);
void getdef(void);
void getundef(void);

#endif
