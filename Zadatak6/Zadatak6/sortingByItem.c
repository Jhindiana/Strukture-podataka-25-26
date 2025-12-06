#include "allHeaders.h"
int addToArticle(articlePosition q, const char* x, int y, double z) {
	articlePosition toAdd = newArticle(x, y, z);
	if (toAdd == NULL) {
		printf("Greska u alokaciji toAdd\n");
		return -1;
	}
	articlePosition temp = q;
	while (temp->next != NULL && (strcmp(temp->next->item, toAdd->item) < 0)) {
		temp = temp->next;
	}
	toAdd->next = temp->next;
	temp->next = toAdd;
	return 0;
}

articlePosition newArticle(const char* a, int b, double c) {
	articlePosition nA = (articlePosition)malloc(sizeof(article));
	if (nA == NULL) {
		printf("Greska pri alokaciji u addToArticle\n");
		return NULL;
	}
	strcpy(nA->item, a);
	nA->quantity = b;
	nA->price = c;
	nA->next = NULL;
	return nA;
}