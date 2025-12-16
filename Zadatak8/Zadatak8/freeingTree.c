#include "headers.h"
Position freeingTree(Position root) {
	if (root != NULL) {
		freeingTree(root->leftChild);
		freeingTree(root->rightChild);
		free(root);
	}
	return NULL;
}