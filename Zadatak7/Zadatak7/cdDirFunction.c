#include "headers.h"
int cdDirFunction(stogPosition s, stogPosition level) {
	char folder[MAX];
	Position check = level->nodePosition->child;
	stogPosition nextInStog = (stogPosition)malloc(sizeof(stog));
	if (!nextInStog) {
		printf("Greska u alokaciji u cdDirFunction\n");
		return -1;
	}
	if (check == NULL) {
		printf("Nema dir za uci\n");
		return 0;
	}
	printf("Unesite u koji dir ulazite: \n");
	dirFunction(s);
	printf(":");
	if (scanf(" %[^\n]", &folder) != 1) {
		printf("Greska pri unosu stringa u cdDirFunction\n");
		return -1;
	}
	while (check != NULL) {
		if (strcmp(check->name, folder) == 0) {
			push(s, check);
			nextInStog->nodePosition = check;
		}
		check = check->brother;
	}
	return 0;
}