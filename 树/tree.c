#include <stdio.h>
#include <memory.h>
#include "BST.h"

int intCompare(void *a, void *b)
{
	int x = *(int*)a, y = *(int*)b;
	if (x == y)
	{
		return 0;
	}
	else if (x < y)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

void intPrint(void *a)
{
	int x = *(int*)a;
	printf("%d\n", x);
}

void testIntBST()
{
	int a[12] = { 36,72,12,57,87,89,14,1,0,7,13,76 };
	int i = 0, key = 36;
	BST *tree = NULL;
	node *nd = NULL;

	tree = (BST *)calloc(1, sizeof(BST));
	tree->cmp = intCompare;
	tree->prt = intPrint;

	for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		insert(tree, (a + i));
	}
	inOrder(tree, tree->root);

	nd = find(tree, &key);
	if (nd)
	{
		printf("\nfind node ");
		(*tree->prt)(nd->data);
	}

	del(tree, &key);
	printf("\nafter delete node %d:\n", key);
	inOrder(tree, tree->root);

	return;
}

int main()
{
	testIntBST();
	return 0;
}