#include "allHeaders.h"
int sortingByDate(Position q) {
	int n = countingBills(q);
	Position* ar = makingArray(q, n);
	qsort(ar, n, sizeof(Position), comparingDates);
	sortingTheList(q, ar, n);
	free(ar);
	return 0;
}
int countingBills(Position q) {
	Position temp = q->next;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}
Position* makingArray(Position q, int x) {
	Position* array = (Position*)malloc(sizeof(Position) * x);
	Position temp = q->next;
	for (int i = 0; i < x; i++) {
		array[i] = temp;
		temp = temp->next;
	}
	return array;
}
int comparingDates(const void* a, const void* b) {
	Position A = *(Position*)a;
	Position B = *(Position*)b;

	if (A->year != B->year)
		return A->year - B->year;

	if (A->month != B->month)
		return A->month - B->month;

	return A->day - B->day;
}

int sortingTheList(Position q, Position* array, int x) {
	for (int i = 0; i < x - 1; i++) {
		array[i]->next = array[i + 1];
	}
	array[x - 1]->next = NULL;
	q->next = array[0];
	return 0;
}