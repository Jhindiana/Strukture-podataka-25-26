/* Napisati program koji iz datoteke cita postfiks izraz i zatim koristenjem stoga racuna
rezultat. Stog je potrebno realizirati preko vezane liste.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct postfix* Position;
typedef struct postfix {
	double number;
	Position next;
}postfix;

int loadingPostfix(Position);
int push(Position, double);
double pop(Position);
int counting(Position, char);
int printing(Position);

int main() {
	postfix head = { .next = NULL };
	loadingPostfix(&head);
	printf("Rezultat: %lf\n", head.next->number);
	return 0;
}

int loadingPostfix(Position q) {
	FILE* fp = fopen("tekst.txt", "r");
	char buffer[MAX];
	if (fp == NULL) {
		printf("Greska pri otvaranju datoteke\n");
		return -1;
	}
	if (!fgets(buffer, sizeof(buffer), fp)) {
		printf("Greska pri ucitavanju iz datoteke\n");
		fclose(fp);
		return -1;
	}
	fclose(fp);
	char number;
	for (int i = 0; buffer[i] != '\0'; i++) {
		number = buffer[i];
		if (number >= '0' && number <= '9') {
			push(q, number - '0');
		}
		else if (number == '+' || number == '-' || number == '*' || number == '/') {
			counting(q, number);
		}
	}
	return 0;
}

int push(Position q, double x) {
	Position p = (Position)malloc(sizeof(postfix));
	if (p == NULL) {
		printf("Greska pri alokaciji memorije\n");
		return -1;
	}
	p->number = x;
	p->next = q->next;
	q->next = p;
	return 0;
}

double pop(Position q) {
	if (q->next == NULL) {
		printf("Stog je prazan\n");
		return 0;
	}
	Position temp = q->next;
	double value = temp->number;
	q->next = temp->next;
	temp->next = NULL;
	free(temp);
	return value;
}

int counting(Position q, char s) {
	double a = pop(q);
	double b = pop(q);
	double result = 0;
	switch (s) {
	case '+':
		result = b + a;
		break;
	case '-':
		result = b - a;
		break;
	case '*':
		result = b * a;
		break;
	case '/':
		if (a == 0) {
			printf("Nemoze se dijeliti s nulom\n");
			return -1;
		}
		result = b / a;
		break;
	default:
		printf("Lose ucitan znak\n");
		return -1;
	}
	push(q, result);
	return 0;
}
