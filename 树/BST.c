#include <stdio.h>
#include <malloc.h>
#include "BST.h"

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
		printf("----");
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
		printf("----");
	}

	(*tree->prt)(nd->data);
	preOrder(tree, nd->left, sp + 1);
	preOrder(tree, nd->right, sp + 1);
	return 0;
}

int postOrder(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}
	postOrder(tree, nd->left, sp + 1);
	postOrder(tree, nd->right, sp + 1);
	for (i; i < sp; i++)
	{
		printf("----");
	}

	(*tree->prt)(nd->data);
	return 0;
}
