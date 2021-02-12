#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "exercise_6.h"

#define MAXLIST 1000

static int numlist = 0;
static Word *list[MAXLIST];

static void addtolist(Node *);
static void sortlist();

int main(void)
{
	Node *root = NULL;
	char string[LEN];
	int rc;

	while ((rc = getword_2(string, LEN)) != EOF) {
		if (rc == '\n')
			continue;
		if (isalpha(string[0]) && strlen(string) > 1) {
			if (!root)
				root = addNode(root, string);
			else
				addNode(root, string);
		}
	}
	addtolist(root);
	sortlist();
	for (int i = 0; i < numlist; i++)
		printf("%2d:%20s\n", list[i]->count, list[i]->word);
	deleteTree(root);

	return 0;
}
static void addtolist(Node *root)
{
	if (root) {
		addtolist(root->left);
		if (numlist < MAXLIST)
			list[numlist++] = &root->word;
		addtolist(root->right);
	}
}
static void sortlist()
{
	int gap, i, j;
	Word *temp;

	for (gap = numlist/2; gap > 0; gap /= 2)
		for (i = gap; i < numlist; i++)
			for (j = i-gap; j >= 0; j -= gap) {
				if ((list[j]->count) >= (list[j+gap]->count))
					break;
				temp = list[j];
				list[j] = list[j+gap];
				list[j+gap] = temp;
			}
}
