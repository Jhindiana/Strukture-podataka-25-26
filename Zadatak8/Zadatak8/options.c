#include"headers.h"
int options(Position root) {
	int option;
	do {
		printf("Odaberite jednu od opcija: \n");
		printf("1 za dodavanje novog elementa u stablo\n");
		printf("2 za ispis elemenata\n");
		printf("3 za brisanje elementa\n");
		printf("4 za pronalazenje nekog elementa\n");
		printf("5 = izlaz iz programa\n");
		if (scanf("%d", &option) != 1) {
			printf("Greska pri unosu opcije\n");
			break;
		}
		caseFunctions(root, option);
	} while (option != 5);
	return 0;
}