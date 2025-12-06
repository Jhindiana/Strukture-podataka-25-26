/*6. Napisati program koji cita datoteku racuni.txt u kojoj su zapisani nazivi svih datoteka koji
predstavljaju pojedini racun. Na pocetku svake datoteke je zapisan datum u kojem vremenu je
racun izdat u formatu YYYY-MM-DD. Svaki sljedeci red u datoteci predstavlja artikl u formatu
naziv, kolicina, cijena. Potrebno je formirati vezanu listu racuna sortiranu po datumu. Svaki cvor
vezane liste sadrzava vezanu listu artikala sortiranu po nazivu artikla. Nakon toga potrebno je
omoguciti upit kojim će korisnik saznati koliko je novaca sveukupno potroseno na specificni
artikl u odredenom vremenskom razdoblju i u kojoj je kolicini isti kupljen.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allHeaders.h"

int main() {
	Bill headBill = { .next = NULL };
	stats statHead = { .nextStat = NULL };
	stats statHeadPrice = { .nextStat = NULL };
	addingBills(&headBill);
	options(&headBill, &statHead, &statHeadPrice);
	while (headBill.next != NULL) {
		while (headBill.articleNext != NULL) {
			freeingArticlePosition(headBill.articleNext);
		}
		freeingPosition(&headBill);
	}
	while (headBill.next != NULL) {
		freeingStatPosition(&statHead);
	}
	while (headBill.next != NULL) {
		freeingStatPosition(&statHeadPrice);
	}
	return 0;
}