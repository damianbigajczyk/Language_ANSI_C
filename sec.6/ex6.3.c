#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "exercise_6.h"

#define NUM 100

typedef struct word {
	char *string;
	int count;
	int line[NUM];
} word;
typedef struct node {
	word word;
	struct node *left;
	struct node *right;
} Node;

Node *addNode(Node *p, char *word, int line);
void displayTree(Node *root);
void deleteTree(Node *root);

int main(void)
{
	int rc;
	char word[MAXWORD];
	int line = 1;
	Node *root = NULL;

	while ((rc = getword_2(word, MAXWORD)) != EOF) {
		if (rc == '\n') {
			++line;
			continue;
		}
		if (isalpha(word[0]) && strlen(word) > 1) {
			if (!root)
				root = addNode(root, word, line);
			else
				addNode(root, word, line);
		}
	}
	displayTree(root);
	deleteTree(root);

	return 0;
}
Node *addNode(Node *p, char *word, int line)
{
	int rc;

	if (!p) {
		p = (Node *) malloc(sizeof(Node));
		if (!p) {
			fprintf(stderr, "Failed to allocate memory for new Node\n");
			return NULL;
		}
		p->word.string = strdup(word);
		if (!p->word.string) {
			fprintf(stderr, "Failed to allocate memory for new Node\n");
			free(p);
			return p = NULL;
		}
		memset(p->word.line, -1, NUM * sizeof(int));
		p->word.count = 1;
		p->word.line[0] = line;
	}
	else if ((rc = strcmp(word, p->word.string)) == 0)
			p->word.line[p->word.count++] = line;
	else if (rc < 0)
		p->left = addNode(p->left, word, line);
	else
		p->right = addNode(p->right, word, line);
	return p;
}
void displayTree(Node *root)
{
	if (root) {
		displayTree(root->left);
		printf("%d %s: ", root->word.count, root->word.string);
		for (int i = 0; root->word.line[i] != -1; i++)
			printf("%d, ", root->word.line[i]);
		putchar('\n');
		displayTree(root->right);
	}
}
void deleteTree(Node *root)
{
	Node *p_right;
	if (root) {
		p_right = root->right;
		deleteTree(root->left);
		free(root->word.string);
		free(root);
		root = NULL;
		deleteTree(p_right);
	}
}
