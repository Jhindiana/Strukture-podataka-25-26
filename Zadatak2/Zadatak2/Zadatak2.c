/*Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste,
B. ispisuje listu,
C. dinamicki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. brise odredeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.


Prethodnom zadatku dodati funkcije:
A. dinamicki dodaje novi element iza odredenog elementa,
B. dinamicki dodaje novi element ispred odredenog elementa,
C. sortira listu po prezimenima osoba,
D. upisuje listu u datoteku,
E. cita listu iz datoteke.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //EXIT_FAILURE
#include <string.h>

struct Person;
typedef struct Person* Position;
typedef struct Person {
	char name[50];
	char lastName[50];
	int birthYear;
	Position next;
}Person;

int inputStart(Position, int);
int inputEnd(Position, int);
int loop(Position);
int printing(Position);
int findingElement(Position);
int erasingElement(Position);
int inputAfterElement(Position);
int inputBeforeElement(Position);
int sortingList(Position);//amogus
int inputingIntoFile(Position);
int readingList(Position);
int writingInFile(Position);
int printingFromFile();

int main() {
	char a = 'y', b;
	int temp, pozicija;
	Person head = { .next = NULL };
	if (loop(&head) == -1) {
		printf("Greska pri unosu broja osoba. \n");
		return -1;
	}
	while (a == 'y' || a == 'Y') {
		printf("Zelite li unijeti jos osoba(Y ili N)? ");
		if (scanf(" %c", &a) != 1) {
			printf("Greska pri citanju. ");
			return -1;
		}
		if (a == 'n' || a == 'N') {
			break;
		}
		printf("Zelite li ih dodati ispred(1)/iza(2) nekog elementa ili na pocetak/kraj(3) liste? ");
		scanf(" %d", &pozicija);
		switch (pozicija) {
		case 1:
			inputBeforeElement(&head);
			break;
		case 2:
			inputAfterElement(head.next);
			break;
		case 3:
			loop(&head);
			break;
		default:
			printf("Greska pri ucitavanju broja. \n");
			break;
		}
	}
	printing(head.next);
	printf("Zelite li pronaci osobu u listi(Y ili N)?");
	scanf(" %c", &b);
	if (b == 'y' || b == 'Y') {
		printf("Koje prezime trazite: ");
		temp = findingElement(head.next);
		if (temp == NULL) {
			printf("Trazeno prezime se ne nalazi u listi. \n");
			return 0;
		}
		else {
			printf("Trazeno prezime je na poziciji: %d\n", temp + 1);
		}
	}
	printing(head.next);
	printf("Zelite li izbrisati osobu iz liste(Y ili N)?");
	scanf(" %c", &b);
	if (b == 'y' || b == 'Y') {
		erasingElement(&head);
	}
	printing(head.next);
	sortingList(&head);
	printf("Sortirana lista:\n");
	printing(head.next);
	writingInFile(head.next);
	printf("Ispis iz filea: \n");
	printingFromFile();
	return 0;
}

int inputStart(Position q, int x) {
	Position p = (Position)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Greska u alokaciji memorije.\n ");
		return -1;
	}
	p->next = q->next;
	q->next = p;
	printf("Ime %d. osobe: ", x + 1);
	scanf(" %s", p->name);
	printf("Prezime %d. osobe: ", x + 1);
	scanf(" %s", p->lastName);
	printf("Godina rodenja %d. osobe: ", x + 1);
	scanf("%d", &p->birthYear);
	return 0;
}

int inputEnd(Position q, int x) {
	Position p = (Position)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Greska u alokaciji memorije.\n ");
		return -1;
	}
	while (q->next != NULL) {
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	printf("Ime %d. osobe: ", x + 1);
	scanf(" %s", p->name);
	printf("Prezime %d. osobe: ", x + 1);
	scanf(" %s", p->lastName);
	printf("Godina rodenja %d. osobe: ", x + 1);
	scanf("%d", &p->birthYear);
	return 0;
}

int loop(Position q) {
	int n, i;
	char z;
	printf("Unesite koliko osoba unosite: ");
	if (scanf("%d", &n) != 1) {
		return -1;
	}
	printf("Unosite li na pocetak ili kraj liste(S/s ili E/e)? ");
	if (scanf(" %c", &z) != 1) {
		return -1;
	}
	switch (z) {
	case 's':
	case 'S':
		for (i = 0; i < n; i++) {
			inputStart(q, i);
		}

		break;
	case 'e':
	case 'E':
		for (i = 0; i < n; i++) {
			inputEnd(q, i);
		}

		break;
	default:
		printf("Greska pri unosu. ");
		return -1;
		break;
	}
	return 0;
}

int printing(Position q) {
		while (q != NULL) {
			printf("Ime: %s\n", q->name);
			printf("Prezime: %s\n", q->lastName);
			printf("Godina rodenja: %d\n", q->birthYear);
			q = q->next;
		}
		return 0;
	}

int findingElement(Position q) {
	char search[50];
	int i = 0;
	scanf(" %s", &search);
	while (q != NULL && strcmp(q->lastName, search) != 0) {
		q = q->next;
		i++;
	}
	if (q == NULL) {
		return NULL;
	}
	return i;
}

int erasingElement(Position q) {
	Position Del;
	char del[50];
	printf("Koje prezime zelite izbrisati: ");
	if (scanf(" %s", del) != 1) {
		printf("Greska pri citanju prezimena za brisanje.\n");
		return -1;
	}
	while (q->next != NULL && strcmp(q->next->lastName, del) != 0) {
		q = q->next;
	}
	Del = q->next;
	q->next = Del->next;
	Del->next = NULL;
	free(Del);
	return 0;
}

int inputBeforeElement(Position q) {
	char search[50];
	Position p = (Position)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Greska u alokaciji memorije.\n ");
		return -1;
	}
	printf("Ispred kojeg prezimena zelite upisati: ");
	scanf(" %s", &search);
	while (q->next != NULL && strcmp(q->next->lastName, search) != 0) {
		q = q->next;
	}
	if (q == NULL) {
		return NULL;
	}
	p->next = q->next;
	q->next = p;
	printf("Ime osobe: ");
	scanf(" %s", p->name);
	printf("Prezime osobe: ");
	scanf(" %s", p->lastName);
	printf("Godina rodenja osobe: ");
	scanf("%d", &p->birthYear);
	return 0;
}

int inputAfterElement(Position q) {
	char search[50];
	Position p = (Position)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Greska u alokaciji memorije.\n ");
		return -1;
	}
	printf("Iza kojeg prezimena zelite upisati: ");
	scanf(" %s", &search);
	while (q != NULL && strcmp(q->lastName, search) != 0) {
		q = q->next;
	}
	if (q == NULL) {
		return NULL;
	}
	p->next = q->next;
	q->next = p;
	printf("Ime osobe: ");
	scanf(" %s", p->name);
	printf("Prezime osobe: ");
	scanf(" %s", p->lastName);
	printf("Godina rodenja osobe: ");
	scanf("%d", &p->birthYear);

	return 0;
}

int sortingList(Position q) {
	Position p = (Position)malloc(sizeof(Person));
	if (p == NULL) {
		printf("Greska u alokaciji memorije.\n ");
		return -1;
	}
	Position temp = NULL, sorted = NULL, first = q;
	int swap;
	do {
		swap = 0;
		q = first;
		p = first->next;
		while (p->next != sorted) {
			if (strcmp(p->lastName, p->next->lastName) > 0) {
				temp = p->next;
				p->next = temp->next;
				temp->next = p;
				q->next = temp;
				swap = 1;
				q = temp;
			}
			else {
				q = p;
				p = p->next;
			}
		}
		sorted = p;
	} while (swap);
	return 0;
}

int writingInFile(Position q) {
	FILE* fp;
	fp = fopen("sortiranalista.txt", "w");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return -1;
	}
	while (q != NULL) {
		fprintf(fp, "%s %s %d", q->name, q->lastName, q->birthYear);
		q = q->next;
	}
	fclose(fp);
	return 0;
}

int printingFromFile() {
	FILE* fp;
	Person p;
	fp = fopen("sortiranalista.txt", "r");
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return -1;
	}
	while (fscanf(fp, "%s %s %d", p.name, p.lastName, &p.birthYear) == 3) {
		printf("%s %s (%d)\n", p.name, p.lastName, p.birthYear);
	}
	fclose(fp);
	return 0;
}
