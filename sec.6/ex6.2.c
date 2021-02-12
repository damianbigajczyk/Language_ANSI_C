#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "exercise_6.h"

int main(int argc, char **argv)
{
	Node *root = NULL;
	int n;
	char string[LEN];


	n = (argc == 2) ? atoi(argv[1]) : 6;

	while (getword(string, LEN) != EOF) {
		if (isalpha(string[0]) && strlen(string) >= n) {
			if (!root)
				root = addNode(root, string);
			else
				addNode(root, string);
		}
	}
	displayTree(root);
	deleteTree(root);

	return 0;
}
