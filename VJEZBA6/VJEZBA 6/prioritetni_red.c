#include "prioritetni_red.h"
/*
int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + rand() % 5;
	}
	return niz;
}
*/
PRIORITETNI_RED* create(n) {
	PRIORITETNI_RED* red = (PRIORITETNI_RED*)malloc(sizeof(PRIORITETNI_RED));
	red->niz = (ELEMENT*)malloc(10000 * sizeof(ELEMENT));
	red->n = 0;
	return red;
}
void insert(PRIORITETNI_RED*red,int broj){
	red->niz[red->n].prioritet = broj;
	red->n += 1;
	popravi_prema_vrhu(red, red->n - 1);
}
void ispis(PRIORITETNI_RED*red) {
	int i;
	for (i = 0;i < red->n;i++) {
		printf("%d ", red->niz[i].prioritet);
	}
}
/*
void sortiraj_prema_gore(PRIORITETNI_RED* red, int indeks) {
	if (indeks == 0)
		return;
	else if (red->niz[indeks].prioritet > red->niz[(indeks - 1) / 2].prioritet) {
		int temp = red->niz[indeks].prioritet;
		red->niz[indeks].prioritet = red->niz[(indeks - 1) / 2].prioritet;
		red->niz[(indeks - 1) / 2].prioritet = temp;
		sortiraj_prema_gore(red,(indeks - 1) / 2);
	}
}
*/
void popravi_prema_vrhu(PRIORITETNI_RED* b, int c)
{
	if (c < 2)
		return;
	int r = (c - 1) / 2;
	if (b->niz[c].prioritet > b->niz[r].prioritet)
	{
		ELEMENT temp = b->niz[c];
		b->niz[c] = b->niz[r];
		b->niz[r] = temp;
		c = r;
		popravi_prema_vrhu(b, c);
	}
}
void ukloni(PRIORITETNI_RED* red) {
	red->niz[0].prioritet = red->niz[red->n-1].prioritet;
	red->n -= 1;
	popravi_prema_dolje(red, 0);
}
void popravi_prema_dolje(PRIORITETNI_RED* red, int indeks) {
	int swap=0;
	if (indeks >= red->n) {
		return;
	}
	if (2 * indeks + 1 < red->n && 2 * indeks + 2 < red->n) {
		if (red->niz[2 * indeks + 1].prioritet >= red->niz[2 * indeks + 2].prioritet) {
			swap = 2 * indeks + 1;
		}
		else if (red->niz[2 * indeks + 1].prioritet <= red->niz[2 * indeks + 2].prioritet) {
			swap = 2 * indeks + 2;
		}
	}
	if (red->niz[indeks].prioritet < red->niz[swap].prioritet && swap!=0) {
		int temp = red->niz[indeks].prioritet;
		red->niz[indeks].prioritet = red->niz[swap].prioritet;
		red->niz[swap].prioritet = temp;
		popravi_prema_dolje(red, swap);
	}
}


