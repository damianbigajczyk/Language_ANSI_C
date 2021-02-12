#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 1

void error(char *, ...);

int main(int argc, char **argv)
{
	int fd;
	int n;
	char buf[BUFSIZE];

	if (argc < 2)
		error("Usage: %s file\n", *argv);
	while (--argc > 0) {
		fd = open(*++argv, O_RDONLY, 0);
		if (fd == -1)
			error("Failed to open file: %s", *argv);
		while ((n = read(fd, buf, BUFSIZE)) > 0)	
			if (write(1, buf, BUFSIZE) != n)
				error("write erroro on file %s", *argv);
		close(fd);
	}

	return 0;
}
void error(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vprintf(fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
