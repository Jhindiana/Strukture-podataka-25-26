//#include "racuni.h"
//
//
//int loading(Position q) {
//	FILE* fp = fopen("racuni.txt", "r");
//	if (fp == NULL) {
//		printf("Greska pri otvaranju glavnog racuna\n");
//		return -1;
//	}
//	char c[MAX];
//	while (!feof(fp)) {
//		if (fscanf(fp, " %s", &c) == 1) {
//			addToMainList(q, c);
//		}
//	}
//	fclose(fp);
//	return 0;
//}
//
//int addToMainList(Position q, const char* z) {
//	Position nE = (Position)malloc(sizeof(mainReceipt));
//	if (nE == NULL) {
//		printf("Greska pri alokaciji glavnog racuna\n");
//		return -1;
//	}
//	strcpy(nE->mainReceipt, z);
//	nE->next = q->next;
//	q->next = nE;
//	return 0;
//}
//
//int loadingReceipt(datesPosition q, Position mR) {
//	mR = mR->next;
//	while (mR != NULL) {
//		FILE* fp = fopen(mR->mainReceipt, "r");
//		if (fp == NULL) {
//			printf("Greska pri otvaranju datoteka\n");
//			return -1;
//		}
//		char c[MAX];
//		int d, m, y, qu;
//		double pr;
//		while (!feof(fp)) {
//			if (sscanf(fp, "%d-%d-%d", &y, &m, &d) == 3) {
//				addDateToReceipt(q, d, m, y);
//			}
//			if (sscanf(fp, " %s %d %lf", &c, &qu, &pr) == 3) {
//				addItemToReceipt(q, c, qu, pr);
//			}
//		}
//		fclose(fp);
//		mR = mR->next;
//	}
//	return 0;
//}
//
//int addDateToReceipt(datesPosition q, int a, int b, int c) {
//	datesPosition newDate = (datesPosition)malloc(sizeof(dates));
//	newDate->day = a;
//	newDate->month = b;
//	newDate->year = c;
//	while (q->next != NULL) {
//		q = q->next;
//	}
//	newDate->next = q->next;
//	q->next = newDate;
//	return 0;
//}
//
//int addItemToReceipt(receiptPosition q, const char* item, int qu, double pr) {
//	while (q != NULL) {
//		q = q->next;
//	}
//	strcpy(q->item, item);
//	q->quantity = qu;
//	q->price = pr;
//	return 0;
//}
//
//int printing(Position q) {
//	while (q->next != NULL) {
//		printf(" %s", q->mainReceipt);
//		q = q->next;
//	}
//}