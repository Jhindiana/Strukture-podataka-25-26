#pragma once
#include "allHeaders.h"
typedef struct stats* statPosition;
typedef struct stats {
	char name[MAX];
	int overallQuantity;
	double overallPrice;
	int overallCount;
	statPosition nextStat;
}stats;
int options(Position, statPosition, statPosition);
int caseFunction(Position, int, statPosition);
int cheapestArticle(Position);
int mostExpensiveArticle(Position);
int leastProfitable(Position);
int mostProfitable(Position);
int leastBought(Position, statPosition);
int mostBought(Position, statPosition);
int averagePrice(Position, statPosition);
int addingOrUpdatingStats(statPosition, const char*, int);
int addingOrUpdatingPrices(statPosition, const char*, double);
double overallSpending(Position);
double overallSpendingOverTime(Position, int, int, int, int, int, int);
int leastBoughtInTime(Position, statPosition, int, int, int, int, int, int);
int mostBoughtInTime(Position, statPosition, int, int, int, int, int, int);