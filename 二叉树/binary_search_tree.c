#include <stdio.h>
#include <malloc.h>

typedef int (*compare)(void*, void*);
typedef void (*print)(void*);

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

typedef struct nodeTag node;
typedef struct binarySearchTree BST;

struct nodeTag
{
	node *parent;
	node *left;
	node *right;
	void *data;
};

struct binarySearchTree
{
	node *root;
	compare cmp;
	print prt;
};

int insert(BST *tree, void *val);
int del(BST *tree, void *val);
node* find(BST *tree, node *root, void *val);
int inOrder(BST *tree, node *nd, int sp);
int preOrder(BST *tree, node *nd, int sp);
int postOrder(BST *tree, node *nd, int sp);

int insert(BST *tree, void *val)
{
	node *nd = NULL;
	if (!tree || !val)
	{
		return -1;
	}
	nd = (node *)calloc(1, sizeof(node));
	if (!nd)
	{
		return -1;
	}
	nd->data = val;
	
	if (!tree->root)
	{
		nd->parent = NULL;
		nd->left = NULL;
		nd->right = NULL;
		tree->root = nd;
	}
	else
	{
		node *pre = NULL, *cur = NULL;
		cur = tree->root;
		while (1)
		{
			pre = cur;
			if ((*tree->cmp)(nd->data, cur->data) <= 0)
			{ 
				cur = cur->left;
				if (!cur)
				{
					nd->parent = pre;
					pre->left = nd;
					break;
				}
			}
			else
			{
				cur = cur->right;
				if (!cur)
				{
					nd->parent = pre;
					pre->right = nd;
					break;
				}
			}
		}
	}
	return 0;
}

int del(BST *tree, void *val)
{
	node *nd = NULL;
	if (!tree || !val)
	{
		return -1;
	}
	nd = find(tree, tree->root, val);
	if (nd)
	{
	}
	return 0;
}

node* find(BST *tree, node* root, void *val)
{
	int cmpResult = 0;
	if (!tree || !root || !val)
	{
		return NULL;
	}
	cmpResult = (*tree->cmp)(root->data, val);
	if (cmpResult == 0)
	{
		return root;
	}
	else if (cmpResult < 0)
	{
		return find(tree, root->right, val);
	}
	else
	{
		return find(tree, root->left, val);
	}
}

int inOrder(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}
	inOrder(tree, nd->left, sp + 1);
	for (i ; i < sp; i++)
	{
		printf("--");
	}
	
	(*tree->prt)(nd->data);
	inOrder(tree, nd->right, sp + 1);
	return 0;
}

int preOrder(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}
	for (i; i < sp; i++)
	{
		printf("--");
	}

	(*tree->prt)(nd->data);
	inOrder(tree, nd->left, sp + 1);
	inOrder(tree, nd->right, sp + 1);
	return 0;
}

int postOrder(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}
	inOrder(tree, nd->left, sp + 1);
	inOrder(tree, nd->right, sp + 1);
	for (i; i < sp; i++)
	{
		printf("--");
	}

	(*tree->prt)(nd->data);
	return 0;
}

void testIntTree()
{
	int a[10] = { 14,72,12,57,87,987,1,7,48,347 };
	int i = 0;
	BST *tree = NULL;

	tree = (BST *)calloc(1, sizeof(BST));
	tree->cmp = intCompare;
	tree->prt = intPrint;

	for (i = 0; i < 10; i++)
	{
		insert(tree, (a + i));
	}
	inOrder(tree, tree->root, 0);

	return;
}

int main()
{
	testIntTree();
	return 0;
}