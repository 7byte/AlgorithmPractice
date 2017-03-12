#pragma once

#include "tree.h"

typedef struct nodeTag node;

struct nodeTag
{
	node *parent;
	node *left;
	node *right;
	void *data;
};
