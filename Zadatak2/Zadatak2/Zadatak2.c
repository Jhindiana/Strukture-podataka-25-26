/*Definirati strukturu osoba (ime, prezime, godina rodenja) i napisati program koji:
A. dinamicki dodaje novi element na pocetak liste,
B. ispisuje listu,
C. dinamicki dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. brise odredeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.*/
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

int main() {
	char a = 'y', b;
	int temp;
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
		loop(&head);
	}
	printing(head.next);
	printf("Zelite li pronaci osobu u listi(Y ili N)?");
	scanf(" %c", &b);
	if (b == 'y' || b == 'Y') {
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
	printf("Koje prezime trazite: ");
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
	scanf(" %s", del);
	while (q->next != NULL && strcmp(q->next->lastName, del) != 0) {
		q = q->next;
	}
	Del = q->next;
	q->next = Del->next;
	free(Del);
	return 0;
}
