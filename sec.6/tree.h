#ifndef tree_H_
#define tree_H_

#define LEN 20

typedef struct word {
	char *word;
	int count;
} Word;

typedef struct node {
	Word word;
	struct node *left;
	struct node *right;
} Node;

Node *addNode(Node *, char *);
void displayTree(Node *);
void deleteTree(Node *);

#endif
