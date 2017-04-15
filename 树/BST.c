#include <stdio.h>
#include <malloc.h>
#include "BST.h"

//�����������Ӣ�Binary Search Tree����Ҳ�ƶ����������������������Ӣ�ordered binary tree����
//�����������Ӣ�sorted binary tree������ָһ�ÿ������߾����������ʵĶ�������
//		1.������ڵ�����������գ��������������н���ֵ��С�����ĸ�����ֵ��
//		2.������ڵ�����������գ��������������н���ֵ���������ĸ�����ֵ��
//		3.����ڵ����������Ҳ�ֱ�Ϊ�����������
//		4.û�м�ֵ��ȵĽڵ㡣

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
		// �������ڵ�
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
			// �ýڵ�ΪҶ�ӽڵ�
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
			// ��������Ϊ��
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
			// ��������Ϊ��
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
			// ������������Ϊ��
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

	//����������
	inOrderDepth(tree, nd->left, sp + 1);
	
	//��ӡ���ڵ�
	for (i ; i < sp; i++)
	{
		printf("----");
	}	
	(*tree->prt)(nd->data);
	
	//����������
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

	//��ӡ���ڵ�
	for (i; i < sp; i++)
	{
		printf("----");
	}
	(*tree->prt)(nd->data);

	//����������
	preOrderDepth(tree, nd->left, sp + 1);

	//����������
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

	//����������
	postOrderDepth(tree, nd->left, sp + 1);

	//����������
	postOrderDepth(tree, nd->right, sp + 1);

	//��ӡ���ڵ�
	for (i; i < sp; i++)
	{
		printf("----");
	}
	(*tree->prt)(nd->data);

	return 0;
}
