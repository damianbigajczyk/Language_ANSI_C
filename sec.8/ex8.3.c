

int _flushbuf(int x, FILE *pf)
{
	unsigned nc;
	int bufsize;

	if (pf < _iob || pf >= _iob + OPEN_MAX)
		return EOF;
	if ((pf->flag & (_WRITE | _ERR)) != _WRITE)
		return EOF;
	bufsize = (pf->flag & _UNBUF) ? 1 : BUFSIZ;
	if (pf->base == NULL) {
		if ((pf->base = (char *) malloc(bufsize)) == NULL) {
			pf->flag |= _ERR;
			return EOF;
		}
	} else {
		nc = pf->ptr - pf->base;
		if (write(pf->fd, pf->base, nc) != nc) {
			pf->flag |= _ERR;
			return EOF;
		}
	}
	pf->ptr = pf->base;
	*pf->ptr++ = (char) x;
	pf-cnt = bufsize - 1;

	return x;
}
int fflush(FILE *pf)
{
	int rc = 0;

	if (pf < _iob || pf >= _iob + OPEN_MAX)
		return EOF;
	if (pf->flag & _WRITE)
		rc = _flushbuf(0, pf);
	pf->ptr = pf->base;
	pf->cnt = (pf->flag & _UNBUF) ? 1: BUFSIZ;
	return rc;
}
int fclose(FILE *pf)
{
	int rc;

	if ((rc = fflush(pf)) != EOF) {
		free(pf->base);
		pf->ptr = pf->base = NULL;
		pf->cnt = 0;
		pf->flag &= ~(_READ | _WRITE);
	}
	return rc;
}
