/*Napisati program za zbrajanje i mnozenje polinoma. Koeficijenti i eksponenti se
citaju iz datoteke.
Napomena: Eksponenti u datoteci nisu nuzno sortirani.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct poly* Position;
typedef struct poly {
	int coef;
	int pow;
	Position next;
}poly;

int loadingFromFile(Position, Position);
int addition(Position, Position, Position);
int multiplication(Position, Position, Position);
int addingToList(Position, int, int);
int printing(Position);
int deleting(Position);

int main() {
	poly heada = { .coef = 0,.pow = 0,.next = NULL };
	poly firstP = heada;
	poly secondP = heada;
	poly headm = heada;
	loadingFromFile(&firstP, &secondP);
	printf("Prije poziva funkcija\n");
	printf("Prvi polinom: \n");
	printing(firstP.next);
	printf("Drugi polinom: \n");
	printing(secondP.next);
	addition(&heada, firstP.next, secondP.next);
	multiplication(&headm, firstP.next, secondP.next);
	printf("Printanje sume\n");
	printing(heada.next);
	printf("Printanje umnozka\n");
	printing(headm.next);
	while (heada.next != NULL) {
		deleting(&heada);
	}
	while (headm.next != NULL) {
		deleting(&headm);
	}
	while (firstP.next != NULL) {
		deleting(&firstP);
	}
	while (secondP.next != NULL) {
		deleting(&secondP);
	}
	return 0;
}

int loadingFromFile(Position f, Position s) {
	FILE* fp1 = fopen("prviPolinom.txt", "r");
	FILE* fp2 = fopen("drugiPolinom.txt", "r");
	if (fp1 == NULL || fp2 ==NULL) {
		printf("Greska pri otvaranju datoteka.\n");
		return -1;
	}
	int c, p;
	while (!feof(fp1)) {
		if (fscanf(fp1, "%d %d ", &c, &p) != 2) {
			printf("Lose ucitavanje iz datoteka\n");
			return -1;
		}
		if (c != 0) {
			addingToList(f, c, p);
		}
	}
	while (!feof(fp2)) {
		if (fscanf(fp2, "%d %d ", &c, &p) != 2) {
			printf("Lose ucitavanje iz datoteka\n");
			return -1;
		}
		if (c != 0) {
			addingToList(s, c, p);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int addingToList(Position q, int a, int x) {
	Position nP = (Position)malloc(sizeof(poly));
	Position help = q->next;
	if (nP == NULL) {
		printf("Greska pri alokaciji memorije.\n");
		return -1;
	}
	Position start = q;
	q = q->next;
	nP->coef = a;
	nP->pow = x;
	int flag = 0;
	while (help != NULL) {
		if (nP->pow == help->pow) {
			help->coef += nP->coef;
			return 0;
		}
		else {
			help = help->next;
		}
	}
	while (!flag) {
		if (q == NULL) {
			nP->next = start->next;
			start->next = nP;
			flag = 1;
		}
		else if (q->pow > nP->pow) {
			start = q;
			q = q->next;
		}
		else {
			nP->next = q;
			start->next = nP;
			flag = 1;
		}
	}
	return 0;
}

int addition(Position q, Position f, Position s) {
	while (f != NULL && s != NULL) {
		Position nE = (Position)malloc(sizeof(poly));
		if (f ->pow > s->pow) {
			nE->coef = f->coef;
			nE->pow = f->pow;
			nE->next = q->next;
			q->next = nE;
			q = q->next;
			f = f->next;
		}
		else if (f->pow < s->pow) {
			nE->coef = s->coef;
			nE->pow = s->pow;
			nE->next = q->next;
			q->next = nE;
			q = q->next;
			s = s->next;
		}
		else {
			nE->coef = f->coef + s->coef;
			nE->pow = f->pow;
			nE->next = q->next;
			q->next = nE;
			q = q->next;
			f = f->next;
			s = s->next;
		}
	}
	while (f != NULL) {
		Position nE = (Position)malloc(sizeof(poly));
		nE->coef = f->coef;
		nE->pow = f->pow;
		nE->next = q->next;
		q->next = nE;
		q = q->next;
		f = f->next;
	}

	while (s != NULL) {
		Position nE = (Position)malloc(sizeof(poly));
		nE->coef = s->coef;
		nE->pow = s->pow;
		nE->next = q->next;
		q->next = nE;
		q = q->next;
		s = s->next;
	}
	return 0;
}

int multiplication(Position q, Position f, Position s) {
	Position second = s;
	int i, n;
	while (f != NULL) {
		while (second != NULL) {
			i = f->coef * second->coef;
			n = f->pow + second->pow;
			addingToList(q, i, n);
			second = second->next;
		}
		f = f->next;
		second = s;

	}
	return 0;
}

int printing(Position q) {
	while (q != NULL) {
		if (q->coef != 0) {
			printf("%dx^%d\n", q->coef, q->pow);
		}
		q = q->next;
	}
	return 0;
}

int deleting(Position q) {
	Position Del;
	Del = q->next;
	q->next = Del->next;
	Del->next = NULL;
	free(Del);
	return 0;
}