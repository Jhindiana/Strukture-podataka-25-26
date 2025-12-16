/*8. Napisati program koji omoguæava rad s binarnim stablom pretraživanja. Treba
omoguciti unosenje novog elementa u stablo, ispis elemenata (inorder, preorder, postorder i
level order), brisanje i pronalaženje nekog elementa.*/
#include "headers.h"
int main() {
	Position root = NULL;
	int rootValue;
	printf("Unesite prvi element: ");
	scanf("%d", &rootValue);
	root = insertingInRoot(root, rootValue);
	options(root);
	root = freeingTree(root);
	return 0;
}