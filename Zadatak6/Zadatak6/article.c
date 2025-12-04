#include "allHeaders.h"

articlePosition addToArticle(const char* x, int y, double z) {
	articlePosition nA = (articlePosition)malloc(sizeof(article));
	if (nA == NULL) {
		printf("Greska pri alokaciji u addToArticle\n");
		return NULL;
	}
	strcpy(nA->item, x);
	nA->quantity = y;
	nA->price = z;
	nA->next = NULL;
	return nA;
}