#pragma once

#include "tree.h"
#include "binary_tree.h"

typedef struct binarySearchTree BST;

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
