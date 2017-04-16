#pragma once

#include "tree.h"

typedef struct binarySearchTree BST;
typedef struct nodeTag node;

struct nodeTag
{
	node *parent;	//���ڵ�
	node *left;		//�����
	node *right;	//�Ҷ���
	void *data;		//������
};

struct binarySearchTree
{
	node *root;		//���ڵ�
	compare cmp;	//�ȽϺ���
	print prt;		//��ӡ����
};

int insert(BST *tree, void *val);
int del(BST *tree, void *val);
node* find(BST *tree, void *val);
int inOrder(BST *tree, node *nd);
int preOrder(BST *tree, node *nd);
int postOrder(BST *tree, node *nd);
