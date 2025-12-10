#include "headers.h"
int freeingPositionMemory(Position q) {
	if (q == NULL) {
		return 0;
	}
	freeingPositionMemory(q->child);
	freeingPositionMemory(q->brother);
	q->brother = NULL;
	q->child = NULL;
	free(q);
	return 0;
}
int freeingStogPositionMemory(stogPosition s) {
	stogPosition del = s->stogNext;
	s->stogNext = del->stogNext;
	del->stogNext = NULL;
	free(del);
	return 0;
}