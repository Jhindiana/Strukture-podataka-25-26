//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 100
//
//typedef struct mainReceipt* Position;
//typedef struct mainReceipt {
//	char mainReceipt[MAX];
//	Position next;
//	datesPosition datesNext;
//}mainReceipt;
//
//typedef struct dates* datesPosition;
//typedef struct dates {
//	int year;
//	int month;
//	int day;
//	datesPosition next;
//	receiptPosition receiptNext;
//}dates;
//
//typedef struct receipt* receiptPosition;
//typedef struct receipt {
//	int year;
//	int month;
//	int day;
//	char item[MAX];
//	int quantity;
//	double price;
//	receiptPosition next;
//}receipt;
//
//int loading(Position);
//int addToMainList(Position, const char*);
//int loadingReceipt(receiptPosition, Position);
//int addToReceipt(receiptPosition);
//int addDateToReceipt(datesPosition, int, int, int);
//int addItemToReceipt(receiptPosition, const char*, int, double);
//int printing(Position);