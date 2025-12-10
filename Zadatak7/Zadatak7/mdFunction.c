#include "headers.h"
int mdFunction(stogPosition level) {
	char c[MAX];
	stogPosition help = level;
	Position positionTemp = level->nodePosition;
	Position temp = (Position)malloc(sizeof(node));
	if (!temp) {
		printf("Greska pri alokaciji temp u mdFunction\n");
		return -1;
	}
	printf("Unesite ime novog direktorija: ");
	if (scanf(" %[^\n]", &c) != 1) {
		printf("Greska pri unosu stringa u mdFunction\n");
		return -1;
	}
	temp = newNode(c);
	temp->brother = positionTemp->child;
	positionTemp->child = temp;
	return 0;
}