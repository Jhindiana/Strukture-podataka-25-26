#include "headers.h"
Position deletingElement(Position root, int toDelete) {
	Position temp;
	if (root == NULL) {
		return NULL;
	}
	else {
		if (root->value > toDelete) {
			root->leftChild = deletingElement(root->leftChild, toDelete);
		}
		else if (root->value < toDelete) {
			root->rightChild = deletingElement(root->rightChild, toDelete);
		}
		else {
			if (root->leftChild != NULL && root->rightChild != NULL) {
				temp = minElement(root->rightChild);
				root->value = temp->value;
				root->rightChild = deletingElement(root->rightChild, temp->value);
			}
			else {
				temp = root;
				if (root->leftChild == NULL) {
					root = root->rightChild;
				}
				else {
					root = root->leftChild;
				}
				free(temp);
			}
		}
	}
	return root;
}
Position minElement(Position root) {
	if (root == NULL) {
		return NULL;
	}
	while (root->leftChild != NULL) {
		root = root->leftChild;
	}
	return root;
}