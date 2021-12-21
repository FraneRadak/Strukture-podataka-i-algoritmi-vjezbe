#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#define maks = 100000;
typedef struct {
	void* pointer;
	int prioritet;
}ELEMENT;

typedef struct {
	ELEMENT*niz;
	int n;
}PRIORITETNI_RED;


PRIORITETNI_RED* create(n);
void insert(PRIORITETNI_RED* red, int broj);
void ispis(PRIORITETNI_RED* red);
void sortiraj_prema_gore(PRIORITETNI_RED* red, int indeks);
void ukloni(PRIORITETNI_RED* red);
void popravi_prema_dolje(PRIORITETNI_RED* red, int indeks);
void popravi_prema_vrhu(PRIORITETNI_RED* b, int c);
