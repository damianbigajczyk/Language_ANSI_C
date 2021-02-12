#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node *addNode(Node *p, char *w)
{
	int rc;

	if (!p) {
		p = (Node *) malloc(sizeof(Node));
		if (!p) {
			fprintf(stderr, "Failed to allocate memory for Node\n");
			return p;
		}
		p->word.word = strdup(w);
		if (p->word.word == NULL) {
			fprintf(stderr, "Faile to allocate memory for string\n");
			free(p);
			return NULL;
		}
		p->word.count = 1;
		p->left = p->right = NULL;
	} else if ((rc = strcmp(p->word.word, w)) == 0 )
		p->word.count++;
	else if (rc > 0)
		p->left = addNode(p->left, w);
	else
		p->right = addNode(p->right, w);
	
	return p;
}
void displayTree(Node *root)
{
	if (root != NULL) {
		displayTree(root->left);
		printf("%4d %s\n", root->word.count, root->word.word);
		displayTree(root->right);
	}
}
void deleteTree(Node *p)
{
	Node *right;

	if (p != NULL) {
		right = p->right;
		deleteTree(p->left);
		free(p->word.word);
		free(p);
		deleteTree(right);
		p = NULL;
	}	
}
