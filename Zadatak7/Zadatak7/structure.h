#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef struct node* Position;
typedef struct node {
	char name[MAX];
	Position brother;
	Position child;
}node;

typedef struct stog* stogPosition;
typedef struct stog {
	Position nodePosition;
	stogPosition stogNext;
}stog;