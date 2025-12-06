#include "allHeaders.h"
int options(Position q, statPosition stat, statPosition average) {
	int option;
	printf("\t----Racuni----\n");
	ispis(q);
	
	printf("Unesite:\n"); 
	do {
		printf("(1) za ispisati najjeftiniji proizvod\n");
		printf("(2) za ispisati najskuplji proizvod\n");
		printf("(3) za ispisati najmanje profitan racun\n");
		printf("(4) za ispisati najvise profitan racun\n");
		printf("(5) za ispisati najmanje kupljen proizvod\n");
		printf("(6) za ispisati najvise kupljen proizvod\n");
		printf("(7) za ispisati najmanje kupljen proizvod u nekom razdoblju\n");
		printf("(8) za ispisati najvise kupljen proizvod u nekom razdoblju\n");
		printf("(9) za ispis ukupne potrosnje\n");
		printf("(10) za ispis postrosnje u odredenom vremenu\n");
		printf("(0) za prekid programa\n");
		if (scanf("%d", &option) != 1) {
			printf("Lose unesena opcija\n");
			break;
		}
		caseFunction(q, option, stat);
	} while (option != 0);
	return 0;
}
int caseFunction(Position q, int x, statPosition stat) {
	int y1, y2, m1, m2, d1, d2;
	switch (x) {
	case 1:
		cheapestArticle(q);
		break;
	case 2:
		mostExpensiveArticle(q);
		break;
	case 3:
		leastProfitable(q);
		break;
	case 4:
		mostProfitable(q);
		break;
	case 5:
		leastBought(q, stat);
		break;
	case 6:
		mostBought(q, stat);
		break;
	case 7:
		printf("Unesi datume1: godina misec dan\n");
		scanf("%d %d %d", &y1, &m1, &d1);
		printf("Unesi datume2: godina misec dan\n");
		scanf("%d %d %d", &y2, &m2, &d2);
		printf("Najmanje kupljen proizvod u trazenom vremenu je\n");
		leastBoughtInTime(q, stat, y1, y2, m1, m2, d1, d2);
		break;
	case 8:
		printf("Unesi datume1: godina misec dan\n");
		scanf("%d %d %d", &y1, &m1, &d1);
		printf("Unesi datume2: godina misec dan\n");
		scanf("%d %d %d", &y2, &m2, &d2);
		printf("Najvise kupljen proizvod u trazenom vremenu je\n");
		mostBoughtInTime(q, stat, y1, y2, m1, m2, d1, d2);
		break;
	case 9:
		printf("Ukupna potrosnja %.2lf\n", overallSpending(q));
		break;
	case 10:
		printf("Unesi datume1: godina misec dan\n");
		scanf("%d %d %d", &y1, &m1, &d1);
		printf("Unesi datume2: godina misec dan\n");
		scanf("%d %d %d", &y2, &m2, &d2);
		printf("Postrosnja u trazenom vremenu je %.2lf\n", overallSpendingOverTime(q, y1, y2, m1, m2, d1, d2));
		break;
	default:
		printf("Prekid programa\n");
		break;
	}
	return 0;
}
int cheapestArticle(Position q) {
	Position temp = q->next;
	articlePosition cheapest, cheapestOverAll, help;
	cheapestOverAll = temp->articleNext->next;
	while (temp != NULL) {
		cheapest = temp->articleNext->next;
		help = cheapest->next;
		while (help != NULL) {
			if (help->price < cheapest->price) {
				cheapest = help;
			}
			help = help->next;
		}
		if (cheapestOverAll->price > cheapest->price) {
			cheapestOverAll = cheapest;
		}
		temp = temp->next;
	}
	printf("%s %.2lf\n", cheapestOverAll->item, cheapestOverAll->price);
	return 0;
}
int mostExpensiveArticle(Position q) {
	Position temp = q->next;
	articlePosition priciest;
	double expensivePrice;
	double finalPrice = 0;
	char expensiveItem[MAX];
	char finalItem[MAX];
	while (temp != NULL) {
		priciest = temp->articleNext->next;
		expensivePrice = priciest->price;
		strcpy(expensiveItem, priciest->item);
		while (priciest != NULL) {
			if (expensivePrice < priciest->price) {
				expensivePrice = priciest->price;
				strcpy(expensiveItem, priciest->item);
			}
			priciest = priciest->next;
		}
		temp = temp->next;
		if (finalPrice < expensivePrice) {
			strcpy(finalItem, expensiveItem);
			finalPrice = expensivePrice;
		}
	}
	printf("%s; cijena %.2lf\n", finalItem, finalPrice);
	return 0;
}
int leastProfitable(Position q) {
	Position temp = q->next, leastProfitableBill = q->next;
	articlePosition help;
	double sum;
	int i = 0, n = 0;
	double min;
	double* arrayOfSum = malloc(sizeof(double) * countingBills(q));
	if (arrayOfSum == NULL) {
		printf("Greska kod arrayOfSum\n");
		return -1;
	}
	while (temp != NULL) {
		help = temp->articleNext->next;
		sum = 0;
		while (help != NULL) {
			sum += help->quantity * help->price;
			help = help->next;
		}
		arrayOfSum[i] = sum;
		i++;
		temp = temp->next;
	}
	min = arrayOfSum[0];
	for (i = 0; i < countingBills(q); i++) {
		if (min > arrayOfSum[i]) {
			n = i;
			min = arrayOfSum[i];
		}
	}
	for (i = 0; i < n; i++) {
		leastProfitableBill = leastProfitableBill->next;
	}
	printf("%s %.2lf\n", leastProfitableBill->bill, min);
	return 0;
}
int mostProfitable(Position q) {
	Position temp = q->next, mostProfitableBill = q->next;
	articlePosition help;
	double sum;
	int i = 0, n = 0;
	double max;
	double* bird = malloc(sizeof(double) * countingBills(q));
	if (bird == NULL) {
		printf("Greska kod arrayOfSum\n");
		return -1;
	}
	while (temp != NULL) {
		help = temp->articleNext->next;
		sum = 0;
		while (help != NULL) {
			sum += help->quantity * help->price;
			help = help->next;
		}
		bird[i] = sum;
		i++;
		temp = temp->next;
	}
	max = bird[0];
	for (i = 0; i < countingBills(q); i++) {
		if (max < bird[i]) {
			n = i;
			max = bird[i];
		}
	}
	for (i = 0; i < n; i++) {
		mostProfitableBill = mostProfitableBill->next;
	}
	printf("%s %.2lf\n", mostProfitableBill->bill, max);
	//loord i cant chaaange
	//wont you flyyy hiiighhh
	free(bird);
	//yeeaaaahhhh
	return 0;
}
int leastBought(Position q, statPosition stat) {
	Position temp = q->next;
	articlePosition	help;
	while (temp != NULL) {
		help = temp->articleNext->next;
		while (help != NULL) {
			addingOrUpdatingStats(stat, help->item, help->quantity);
			help = help->next;
		}
		temp = temp->next;
	}
	statPosition stats = stat->nextStat;
	statPosition min = stats;
	stats = stats->nextStat;
	while (stats != NULL) {
		if (stats->overallQuantity < min->overallQuantity) {
			min = stats;
		}
		stats = stats->nextStat;
	}
	printf("Najmanje kupljen proizvod %s %d", min->name, min->overallQuantity);
	return 0;
}
int mostBought(Position q, statPosition stat) {
	Position temp = q->next;
	articlePosition	help;
	while (temp != NULL) {
		help = temp->articleNext->next;
		while (help != NULL) {
			addingOrUpdatingStats(stat, help->item, help->quantity);
			help = help->next;
		}
		temp = temp->next;
	}
	statPosition stats = stat->nextStat;
	statPosition max = stats;
	stats = stats->nextStat;
	while (stats != NULL) {
		if (stats->overallQuantity > max->overallQuantity) {
			max = stats;
		}
		stats = stats->nextStat;
	}
	printf("Najvise kupljen proizvod %s %d", max->name, max->overallQuantity);
	return 0;
}
int averagePrice(Position q, statPosition average) {
	Position temp = q->next;
	articlePosition help;
	while (temp != NULL) {
		help = temp->articleNext->next;
		while (help != NULL) {
			addingOrUpdatingPrices(average, help->item, help->price);
			help = help->next;
		}
		temp = temp->next;
	}
	statPosition final = average->nextStat;
	while (final != NULL) {
		double a = final->overallPrice / final->overallCount;
		printf("%s %.2lf\n", final->name, a);
		final = final->nextStat;
	}
	return 0;
}
int addingOrUpdatingStats(statPosition q, const char* item, int quantity) {
	statPosition temp = q->nextStat;
	while (temp != NULL) {
		if (strcmp(item, temp->name) == 0) {
			temp->overallQuantity += quantity;
		}
		temp = temp->nextStat;
	}
	statPosition newStat = (statPosition)malloc(sizeof(stats));
	newStat->overallQuantity = quantity;
	strcpy(newStat->name, item);
	newStat->nextStat = q->nextStat;
	q->nextStat = newStat;
	return 0;
}
int addingOrUpdatingPrices(statPosition q, const char* item, double price) {
	statPosition temp = q->nextStat;
	while (temp != NULL) {
		if (strcmp(temp->name, item) == 0) {
			temp->overallPrice += price;
			temp->overallCount++;
		}
		temp = temp->nextStat;
	}
	statPosition newStat = (statPosition)malloc(sizeof(stats));
	strcpy(newStat->name, item);
	newStat->overallPrice = price;
	newStat->overallCount = 1;
	newStat->overallQuantity = 0;
	newStat->nextStat = q->nextStat;
	q->nextStat = newStat;
	return 0;
}
double overallSpending(Position q) {
	Position temp = q->next;
	articlePosition help;
	double spending = 0;
	while (temp != NULL) {
		help = temp->articleNext->next;
		while (help != NULL) {
			spending += help->quantity * help->price;
			help = help->next;
		}
		temp = temp->next;
	}
	return spending;
}
double overallSpendingOverTime(Position q, int y1, int y2, int m1, int m2, int d1, int d2) {
	Position temp = q->next;
	articlePosition help;
	double spending = 0;
	while (!(y1 <= temp->year)&& !(m1 <= temp->year)&& !(d1 <= temp->year)) {
		temp = temp->next;
	}
	while (temp != NULL) {
		help = temp->articleNext->next;
		if (temp->year <= y2 && temp->month <= m2 && temp->day <= d2) {
			while (help != NULL) {
				spending += help->quantity * help->price;
				help = help->next;
			}

		}
		temp = temp->next;
	}
	return spending;
}
int leastBoughtInTime(Position q, statPosition stat, int y1, int y2, int m1, int m2, int d1, int d2) {
	Position temp = q->next;
	articlePosition	help;
	while (!(y1 <= temp->year) && !(m1 <= temp->year) && !(d1 <= temp->year)) {
		temp = temp->next;
	}
	while (temp != NULL) {
		help = temp->articleNext->next;
		if (temp->year <= y2 && temp->month <= m2 && temp->day <= d2) {
			while (help != NULL) {
				addingOrUpdatingStats(stat, help->item, help->quantity);
				help = help->next;
			}
		}
		while (help != NULL) {
			addingOrUpdatingStats(stat, help->item, help->quantity);
			help = help->next;
		}
		temp = temp->next;
	}
	statPosition stats = stat->nextStat;
	statPosition min = stats;
	stats = stats->nextStat;
	while (stats != NULL) {
		if (stats->overallQuantity < min->overallQuantity) {
			min = stats;
		}
		stats = stats->nextStat;
	}
	printf("%s\n", min->name);
	return 0;
}
int mostBoughtInTime(Position q, statPosition stat, int y1, int y2, int m1, int m2, int d1, int d2) {
	Position temp = q->next;
	articlePosition	help;
	while (!(y1 <= temp->year) && !(m1 <= temp->year) && !(d1 <= temp->year)) {
		temp = temp->next;
	}
	while (temp != NULL) {
		help = temp->articleNext->next;
		if (temp->year <= y2 && temp->month <= m2 && temp->day <= d2) {
			while (help != NULL) {
				addingOrUpdatingStats(stat, help->item, help->quantity);
				help = help->next;
			}
		}
		while (help != NULL) {
			addingOrUpdatingStats(stat, help->item, help->quantity);
			help = help->next;
		}
		temp = temp->next;
	}
	statPosition stats = stat->nextStat;
	statPosition max = stats;
	stats = stats->nextStat;
	while (stats != NULL) {
		if (stats->overallQuantity > max->overallQuantity) {
			max = stats;
		}
		stats = stats->nextStat;
	}
	printf("%s\n", max->name);
	return 0;
}