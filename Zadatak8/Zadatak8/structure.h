#pragma once
#include "headers.h"
typedef struct tree* Position;
typedef struct tree {
	int value;
	Position leftChild;
	Position rightChild;
}tree;