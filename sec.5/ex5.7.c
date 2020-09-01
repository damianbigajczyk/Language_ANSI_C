#include <stdio.h>
#include <time.h>
#include "exercise_5.h"
#include "sort.h"

#define MAXLINES 5000

int main(void)
{
	int nlines;
	clock_t start, end;
	double exec_time;
	char *lineptr[MAXLINES];
	char linebuf[BUF];

	start = clock();
	if ((nlines = readlines_ver2(lineptr, linebuf, MAXLINES)) >= 0) {
		qsort_1(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
	} else {
		fprintf(stderr, "Error: input too big to sort\n");
		return 1;
	}
	end = clock();
	exec_time = (double)(end - start) / (double)(CLOCKS_PER_SEC);
	printf("Execution time: %.6f\n", exec_time);

	return 0;
}
