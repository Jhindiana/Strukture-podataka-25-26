#include "headers.h"
Position newNode(const char* name) {
	Position nN = (Position)malloc(sizeof(node));
	if (!nN) {
		printf("Greska kod alokacije u firstNode\n");
		return NULL;
	}
	nN->brother = NULL;
	nN->child = NULL;
	strcpy(nN->name, name);
	return nN;
}
int push(stogPosition s, Position node) {
	stogPosition temp = s;
	while (temp->stogNext != NULL) {
		temp = temp->stogNext;
	}
	stogPosition help = (stogPosition)malloc(sizeof(stog));
	if (help == NULL) {
		printf("Greska pri alokaciji u push\n");
		return -1;
	}
	help->nodePosition = node;
	help->stogNext = temp->stogNext;
	temp->stogNext = help;
	return 0;
}
int pop(stogPosition s, stogPosition removing) {
	stogPosition temp = s->stogNext, toRemove=removing;
	while (temp->stogNext != removing) {
		temp = temp->stogNext;
	}
	temp->stogNext = toRemove->stogNext;
	toRemove->stogNext = NULL;
	free(toRemove);
	return 0;
}