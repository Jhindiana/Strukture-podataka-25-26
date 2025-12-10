#include "headers.h"
int options(Position q, stogPosition s) {
	int option;
	stogPosition temp;
	do {
		printf("\n");
		temp = s->stogNext;
		while (temp != NULL) {
			printf("%s/", temp->nodePosition->name);
			temp = temp->stogNext;
		}
		printf("\n");
		printf("Odaberite jednu od opcija: \n");
		printf("1 = md\n");
		printf("2 = cd dir\n");
		printf("3 = cd ..\n");
		printf("4 = dir\n");
		printf("5 = izlaz iz programa\n");
		if (scanf("%d", &option) != 1) {
			printf("Greska pri unosu opcije\n");
			break;
		}
		caseFunctions(q, s, option);
	} while (option != 5);
	printf("Izlaz iz programa\n");
	
	return 0;
}
int caseFunctions(Position q, stogPosition s, int x) {
	stogPosition level = s->stogNext;
	while (level->stogNext != NULL) {
		level = level->stogNext;
	}
	switch (x) {
	case 1:
		printf("Odabrana opcija 1\n");
		mdFunction(level);
		break;
	case 2:
		printf("Odabrana opcija 2\n");
		cdDirFunction(s, level);
		break;
	case 3:
		printf("Odabrana opcija 3\n");
		cdBackFunction(s, level);
		break;
	case 4:
		printf("Odabrana opcija 4\n");
		dirFunction(s);
		break;
	case 5:
		freeingPositionMemory(q->brother);
		while (s->stogNext != NULL) {
			freeingStogPositionMemory(s);
		}
		break;
	default:
		printf("Greska u caseFunctions\n");
		break;
	}
	return 0;
}