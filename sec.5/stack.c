#include <stdio.h>
#include "stack.h"

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(size_t n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp -n;
	} else
		return NULL;
}
void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
