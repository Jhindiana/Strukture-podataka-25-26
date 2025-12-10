#include "headers.h"
int dirFunction(stogPosition s) {
	stogPosition firstStog = s->stogNext, prevStog = s;
	Position helpForPrint;
	while (firstStog != NULL) {
		printf("%s/", firstStog->nodePosition->name);
		prevStog = prevStog->stogNext;
		firstStog = firstStog->stogNext;
	}
	printf(" ");
	helpForPrint = prevStog->nodePosition->child;
	while (helpForPrint != NULL) {
		printf("%s ", helpForPrint->name);
		helpForPrint = helpForPrint->brother;
	}
	return 0;
}