#ifndef dcl_H_
#define dcl_H_

#define BUFSIZE 100
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void undcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);

#endif
