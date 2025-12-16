#include "headers.h"
int treePrinting(Position root) {
	int i;
	printf("Opcije printanja:\n");
	printf("1 - inorder\n");
	printf("2 - preorder\n");
	printf("3 - postorder\n");
	printf("4 - level order\n");
	scanf("%d", &i);
	switch (i) {
	case 1:
		inorder(root);
		break;
	case 2:
		preorder(root);
		break;
	case 3:
		postorder(root);
		break;
	case 4:
		levelOrder(root);
		break;
	default:
		printf("Krivo unesen izbor\n");
		break;
	}
	return 0;
}
int inorder(Position root) {
	if (root != NULL) {
		inorder(root->leftChild);
		printf("%d\t", root->value);
		inorder(root->rightChild);
	}
	return 0;
}
int preorder(Position root) {
	if (root != NULL) {
		printf("%d\t", root->value);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
	return 0;
}
int postorder(Position root) {
	if (root != NULL) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d\t", root->value);
	}
	return 0;
}
int depth(Position root) {
	if (root == NULL) {
		return 0;
	}
	int left, right;
	left = depth(root->leftChild);
	right = depth(root->rightChild);
	return left > right ? left + 1 : right + 1;
}
int levelOrderPrint(Position root, int level) {
	if (root == NULL) {
		return 0;
	}
	if (level == 1) {
		printf("%d ", root->value);
	}
	else {
		levelOrderPrint(root->leftChild, level - 1);
		levelOrderPrint(root->rightChild, level - 1);
	}
	return 0;
}
int levelOrder(Position root) {
	int d = depth(root);
	for (int i = 0; i <= d; i++) {
		levelOrderPrint(root, i);
		printf("\n");
	}
	return 0;
}