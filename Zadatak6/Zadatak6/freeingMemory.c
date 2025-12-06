#include "allHeaders.h"
int freeingPosition(Position q) {
	Position Del;
	Del = q->next;
	q->next = Del->next;
	Del->next = NULL;
	free(Del);
	return 0;
}
int freeingArticlePosition(articlePosition q) {
	articlePosition del;
	del = q->next;
	q->next = del->next;
	del->next = NULL;
	free(del);
	return 0;
}
int freeingStatPosition(statPosition q) {
	statPosition Del;
	Del = q->nextStat;
	q->nextStat = Del->nextStat;
	Del->nextStat = NULL;
	free(Del);
	return 0;
}