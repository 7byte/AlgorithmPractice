#include <stdio.h>
#include <malloc.h>
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
	int a[11] = { 14,72,12,57,87,89,1,0,7,13,76 };
	int i = 0;
	BST *tree = NULL;

	tree = (BST *)calloc(1, sizeof(BST));
	tree->cmp = intCompare;
	tree->prt = intPrint;

	for (i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		insert(tree, (a + i));
	}
	preOrder(tree, tree->root, 0);

	return;
}

int main()
{
	testIntBST();
	return 0;
}