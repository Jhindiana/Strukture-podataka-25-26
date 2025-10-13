/*Napisati program koji prvo procita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinamicki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i ucitati iz datoteke sve zapise. Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrzi ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POINTS 90
#define CHARACTERS 50

typedef struct student{
	char name[CHARACTERS];
	char lastName[CHARACTERS];
	double AbsolutePoints;
} student;

int countingLines(); 
int inputingIntoStruct(student*, int); 
int printingStudents(student);

int main() {
	student* stud;
	int count = countingLines();
	if (!count) {
		printf("Greska pri racunanju redova. \n");
		return 0;
	}
	stud = (student* )malloc(sizeof(student) * count);
	if (stud == NULL) {
		printf("Greska u postavljanju studenata. \n");
		return 0;
	}
	inputingIntoStruct(stud, count);
	for (int j = 0; j < count; j++) {
		printingStudents(stud[j]);
	}
	free(stud);
	return 0;
}

int countingLines() {
	FILE* file = fopen("datoteka.txt", "r");
	int broj = 0;
	if (file == NULL) {
		return 0;
	}
	char ch;
	while ((ch = fgetc(file)) != EOF) {
		if (ch == '\n') {
			broj++;
		}
	}
	fclose(file);
	return broj;
}

int inputingIntoStruct(student* stud, int n) {
	FILE* file = fopen("datoteka.txt", "r");
	int i = 0;
	while (i < n) {
		fscanf(file, "%s %s %lf", stud[i].name, stud[i].lastName, &stud[i].AbsolutePoints);
		i++;
	}
	fclose(file);
	return 0;
}
int printingStudents(student st) {
	if (st.AbsolutePoints > MAX_POINTS) {
		printf("Student %s %s ima vise bodova od dozvoljenih. \n", st.name, st.lastName);
		printf("\n");
	}
	else {
		printf("Ime: %s\n", st.name);
		printf("Prezime: %s\n", st.lastName);
		printf("Broj bodova: %.2lf\n", st.AbsolutePoints);
		printf("Postotak: %.2lf\n", (st.AbsolutePoints / MAX_POINTS) * 100);
		printf("\n");
	}
	return 0;
}

