#include "headers.h"
int cdBackFunction(stogPosition s, stogPosition level) {
	if (s->stogNext == level) {
		printf("Nije dozvoljeno ici korak nazad\n");
		return 0;
	}
	stogPosition temp = s->stogNext;
	while (temp->stogNext != level) {
		temp = temp->stogNext;
	}
	pop(s, temp->stogNext);
	return 0;
}