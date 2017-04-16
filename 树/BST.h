#pragma once

#include "tree.h"

typedef struct binarySearchTree BST;
typedef struct nodeTag node;

struct nodeTag
{
	node *parent;	//父节点
	node *left;		//左儿子
	node *right;	//右儿子
	void *data;		//数据域
};

struct binarySearchTree
{
	node *root;		//根节点
	compare cmp;	//比较函数
	print prt;		//打印函数
};

int insert(BST *tree, void *val);
int del(BST *tree, void *val);
node* find(BST *tree, void *val);
int inOrder(BST *tree, node *nd);
int preOrder(BST *tree, node *nd);
int postOrder(BST *tree, node *nd);
