#include "headers.h"
int caseFunctions(Position root, int value) {
	int n;
	Position found;
	switch (value) {
	case 1:
		printf("Dodavanje novog elementa: \n");
		printf("Unesite novi element: ");
		scanf("%d", &n);
		root = insertingInRoot(root, n);
		break;
	case 2:
		printf("Ispis stabla: \n");
		treePrinting(root);
		printf("\n");
		break;
	case 3:
		printf("Brisanje elementa:\n");
		printf("Unesite koji element brisete: ");
		scanf("%d", &n);
		deletingElement(root, n);
		break;
	case 4:
		printf("Pronalazenje elementa:\n");
		printf("Unesite koji element trazite: ");
		scanf("%d", &n);
		found = findingElement(root, n);
		if (!found) {
			printf("Element %d se ne nalazi u stablu\n", n);
		}
		else {
			printf("element %d se nalazi u stablu\n", n);
		}
		break;
	default:
		printf("Izlaz iz programa\n");
		break;
	}
	return 0;
}