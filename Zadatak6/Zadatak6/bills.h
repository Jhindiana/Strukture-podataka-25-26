#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "article.h"
#define MAX 50

typedef struct Bill* Position;
typedef struct Bill {
	int day;
	int month;
	int year;
	char bill[MAX];
	articlePosition articleNext;
	Position next;
}Bill;

int addingBills(Position);
Position newBill();
int ispis(Position);