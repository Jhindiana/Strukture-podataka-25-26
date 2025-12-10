#include "headers.h"
/*Napisati program koji pomocu vezanih listi (stabala) predstavlja strukturu direktorija.
Omoguciti unos novih direktorija i pod-direktorija, ispis sadrzaja direktorija i
povratak u prethodni direktorij. Tocnije program treba preko menija simulirati
koristenje DOS naredbi: 1- "md", 2 - "cd dir", 3 - "cd..", 4 - "dir" i 5 – izlaz.*/
int main() {
	node headNode = { .brother = NULL,.child = NULL};
	headNode.brother = newNode("C:");
	stog headStog = { .stogNext = NULL };
	push(&headStog, headNode.brother);
	options(&headNode, &headStog);
	headNode.brother = NULL;
	return 0;
}