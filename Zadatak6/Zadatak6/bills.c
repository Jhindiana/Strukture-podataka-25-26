#include "allHeaders.h"

Position newBill() {
	Position nB = (Position)malloc(sizeof(Bill));
	if (nB == NULL) {
		printf("Greska u alokaciji u newBill\n");
		return NULL;
	}
	nB->articleNext = NULL;
	nB->next = NULL;
	return nB;
}

int addingBills(Position q) {
	Position temp = q, help;
	
	char b[MAX], c[MAX];
	int m;
	double n;
	FILE* fp = fopen("racuni.txt", "r");
	if (!fp) {
		printf("Greska pri otvaranju racuni.txt\n");
		return -1;
	}
	while (fscanf(fp, " %s", b) == 1) {
		help = newBill();
		strcpy(help->bill, b);
		FILE* fr = fopen(help->bill, "r");
		if (fr == NULL) {
			printf("Greska pri otvaranju racuna %s\n", help->bill);
			return -1;
		}
		if (fscanf(fr, "%d-%d-%d", &help->year, &help->month, &help->day) != 3) {
			printf("Greska pri citanju datuma\n");
			fclose(fr);
			return -1;
		}
		articlePosition last = NULL;
		while (fscanf(fr, "%s %d %lf", c, &m, &n) == 3) {
			articlePosition articleHelp = addToArticle(c, m, n);
			if (last == NULL) {
				help->articleNext = articleHelp;
			}
			else {
				last->next = articleHelp;
			}
			last = articleHelp;
		}
		
		fclose(fr);
		
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = help;
	}
	fclose(fp);
	sortingByDate(q);

	return 0;
}

int ispis(Position q) {
	q = q->next;
	while (q != NULL) {
		articlePosition temp = q->articleNext;
		printf("%s \nDatum: %d %d %d\n", q->bill, q->year, q->month, q->day);
		if (temp == NULL) {
			printf("temp je null za %s\n", q->bill);
		}
		else {
			while (temp != NULL) {
				printf("%s %d %.2lf\n", temp->item, temp->quantity, temp->price);
				temp = temp->next;
			}
		}
		printf("\n");
		q = q->next;
	}
	return 0;
}