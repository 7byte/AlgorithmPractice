#include <stdio.h>
#include <malloc.h>
#include "BST.h"

//二叉查找树（英语：Binary Search Tree），也称二叉搜索树、有序二叉树（英语：ordered binary tree），
//排序二叉树（英语：sorted binary tree），是指一棵空树或者具有下列性质的二叉树：
//		1.若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
//		2.若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
//		3.任意节点的左、右子树也分别为二叉查找树；
//		4.没有键值相等的节点。

static int inOrderDepth(BST *tree, node *nd, int sp);
static int preOrderDepth(BST *tree, node *nd, int sp);
static int postOrderDepth(BST *tree, node *nd, int sp);
static node* findNode(BST *tree, node* root, void *val);

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
		// 创建根节点
		nd->parent = NULL;
		nd->left = NULL;
		nd->right = NULL;
		tree->root = nd;
	}
	else
	{
		int cmpResult = 0;
		node *pre = NULL, *cur = NULL;
		cur = tree->root;
		while (1)
		{
			pre = cur;
			cmpResult = (*tree->cmp)(nd->data, cur->data);
			if (0 == cmpResult)
			{
				return -1;
			}
			else if (cmpResult < 0)
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
	nd = find(tree, val);
	if (nd)
	{	
		node *q, *s;
		if (!nd->left && !nd->right)
		{
			// 该节点为叶子节点
			if (nd->parent)
			{
				if (nd->parent->left == nd)
				{
					nd->parent->left = NULL;
				}
				else
				{
					nd->parent->right = NULL;
				}
			}
			free(nd);
			nd = NULL;
		}
		else if (!nd->right)
		{
			// 左子树不为空
			q = nd->left;
			nd->data = q->data;
			nd->left = q->left;
			nd->right = q->right;
			if (q->left)
			{
				q->left->parent = nd;
			}
			if (q->right)
			{
				q->right->parent = nd;
			}
			free(q);
			q = NULL;
		}
		else if (!nd->left)
		{
			// 右子树不为空
			q = nd->right;
			nd->data = q->data;
			nd->left = q->left;
			nd->right = q->right;
			if (q->left)
			{
				q->left->parent = nd;
			}
			if (q->right)
			{
				q->right->parent = nd;
			}
		}
		else
		{
			// 左右子树都不为空
			s = nd;
			q = nd->left;
			while (q->right)
			{
				s = q;
				q = q->right;
			}
			nd->data = q->data;
			if (s != nd)
			{
				s->right = q->left;
			}
			else
			{
				s->left = q->left;
			}
			if (q->left)
			{
				q->left->parent = s;
			}
			
			free(q);
			q = NULL;
		}
	}
	return 0;
}

node* find(BST *tree, void *val)
{
	return findNode(tree, tree->root, val);
}

int inOrder(BST *tree, node *nd)
{
	return inOrderDepth(tree, nd, 0);
}

int preOrder(BST *tree, node *nd)
{
	return preOrderDepth(tree, nd, 0);
}

int postOrder(BST *tree, node *nd)
{
	return postOrderDepth(tree, nd, 0);
}

node* findNode(BST *tree, node* root, void *val)
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
		return findNode(tree, root->right, val);
	}
	else
	{
		return findNode(tree, root->left, val);
	}
}

int inOrderDepth(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}

	//遍历左子树
	inOrderDepth(tree, nd->left, sp + 1);
	
	//打印根节点
	for (i ; i < sp; i++)
	{
		printf("----");
	}	
	(*tree->prt)(nd->data);
	
	//遍历右子树
	inOrderDepth(tree, nd->right, sp + 1);

	return 0;
}

int preOrderDepth(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}

	//打印根节点
	for (i; i < sp; i++)
	{
		printf("----");
	}
	(*tree->prt)(nd->data);

	//遍历左子树
	preOrderDepth(tree, nd->left, sp + 1);

	//遍历右子树
	preOrderDepth(tree, nd->right, sp + 1);

	return 0;
}

int postOrderDepth(BST *tree, node *nd, int sp)
{
	int i = 0;
	if (!tree || !nd)
	{
		return -1;
	}

	//遍历左子树
	postOrderDepth(tree, nd->left, sp + 1);

	//遍历右子树
	postOrderDepth(tree, nd->right, sp + 1);

	//打印根节点
	for (i; i < sp; i++)
	{
		printf("----");
	}
	(*tree->prt)(nd->data);

	return 0;
}
