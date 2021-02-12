#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666

typedef struct flag_field {
	unsigned is_read  : 1;
	unsigned is_write : 1;
	unsigned is_unbuf : 1;
	unsigned is_buf   : 1;
	unsigned is_eof   : 1;
	unsigned is_err   : 1;
} Flag;

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	Flag flag;
	int fd;
} FILE;
FILE _iob[OPEN_MAX];



FILE *myfopen(char *, char *);
int _myfillbuf(FILE *);

int main(int argc, char **argv)
{
	FILE *pf = myopen("plik_1", "r");
	if (

	return 0;
}
FILE *myfopen(char *name, char *mode)
{
	int fd;
	FILE *pf;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (pf = _iob; pf < _iob + OPEN_MAX; pf++)
		if (pf->flag.is_read == 0 && pf->flag.is_write == 0)
			break;
	if (pf >= _iob + OPEN_MAX)
		return NULL;
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;
	pf->fd = fd;
	pf->cnt = 0;
	pf->base = NULL;
	pf->flag.is_unbuf = 0;
	pf->flag.is_buf = 1;
	pf->flag.is_eof = 0;
	pf->flag.is_err = 0;
	if (*mode == 'r') {
		pf->flag.is_read = 1;
		pf->flag.is_write = 0;
	} else {
		pf->flag.is_read = 0;
		pf->flag.is_write = 1;
	}
	return pf;
}
int _myfillbuf(FILE *pf)
{
	int bufsize;

	if (pf->flag.is_read == 0 ||
	    pf->flag.is_eof  == 1 ||
	    pf->flag.is_err  == 1)
		return EOF;
	bufsize = (pf->flag.is_unbuf) ? 1: BUFSIZ;
	if (pf->base == NULL)
		if ((pf->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	pf->ptr = pf->base;
	pf->cnt = read(pf->fd, pf->ptr, bufsize);
	if (--pf->cnt < 0) {
		if (pf->cnt == -1)
			pf->flag.is_eof = 1;
		else
			pf->flag.is_err = 1;
		pf->cnt = 0;
		return EOF;
	}
	return (unsigned char) *pf->ptr++;
}
