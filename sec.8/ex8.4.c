
int fseek(FILE *pf, long offset, int origin)
{
	unsigned nc;
	long rc = 0;

	if (pf->flag & _READ) {
		if (origin == 1)
			offset -= pf->cnt;
		rc = lseek(pf->fd, offset, origin);
	} else if (pf->flag & _WRITE) {
		if ((nc = pf->ptr - pf->base) > 0)
			if (write(pf->fd, pf->base, nc) != nc)
				rc = -1;
		if (rc != -1)
			rc = lseek(pf->fd, offset, origin);
	}
	return (rc == -1) ? -1 : 0;
}
