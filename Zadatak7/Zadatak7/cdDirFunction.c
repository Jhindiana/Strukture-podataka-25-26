#include "headers.h"
int cdDirFunction(stogPosition s, stogPosition level) {
	char folder[MAX];
	int isEntered = 0;
	Position check = level->nodePosition->child;
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
		if (!isEntered) {
			if (strcmp(check->name, folder) == 0) {
				push(s, check);
				isEntered = 1;
			}
		}
		check = check->brother;
	}
	if (!isEntered) {
		printf("%s se ne nalazi u ovom direktoriju\n", folder);
	}
	return 0;
}