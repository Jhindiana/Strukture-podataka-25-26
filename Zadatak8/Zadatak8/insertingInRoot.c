#include "headers.h"
Position insertingInRoot(Position root, int valueToInsert) {
	if (root == NULL) {
		root = (Position)malloc(sizeof(tree));
		root->leftChild = NULL;
		root->rightChild = NULL;
		root->value = valueToInsert;
		return root;
	}
	else {
		if (valueToInsert < root->value) {
			root->leftChild = insertingInRoot(root->leftChild, valueToInsert);
		}
		else if (valueToInsert > root->value) {
			root->rightChild = insertingInRoot(root->rightChild, valueToInsert);
		}
		else {
			printf("Vrijednost %d vec postoji u stablu\n", valueToInsert);
		}
	}
	return root;
}