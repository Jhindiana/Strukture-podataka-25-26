#include "headers.h"
Position findingElement(Position root, int valueToFind) {
	if (root == NULL || root->value == valueToFind) {
		return root;
	}
	else {
		if (root->value > valueToFind) {
			return findingElement(root->leftChild, valueToFind);
		}
		else {
			return findingElement(root->rightChild, valueToFind);
		}
	}
}