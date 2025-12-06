#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct article* articlePosition;
typedef struct article {
	char item[MAX];
	int quantity;
	double price;
	articlePosition next;
}article;
