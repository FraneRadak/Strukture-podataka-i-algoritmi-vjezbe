#include "sortiranja.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 10000000;
void main(void) {
	/*
	for (int i = 0;i < 5;i++) {
		int* pointer = generiraj(n);
		shuffle(pointer, n);
		int start = clock();
		quicksort(pointer, n);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		free(pointer);
		n += 1000000;
	}
	printf("*********************************************\n");
	choose_pivot = 0;
	n = 10000;
	for (int i = 0;i < 5;i++) {
		int* pointer = generiraj(n);
		int start = clock();
		quicksort(pointer, n);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		free(pointer);
		n += 1000;
	}
	*/
	/*
	n = 10000000;
	int k=0;
	int* pointer = generiraj(n);
	shuffle(pointer, n);
	while (n_min<=300) {
		int* novi = duplicate(pointer,n);
		int start = clock();
		quicksort(novi, n);
		int stop = clock();
		printf("TIME  %d : %lf\n",k, ((double)(stop - start)) / CLOCKS_PER_SEC);
		free(novi);
		n_min+=5;
		printf("n_min=%d\n",n_min);
		printf("****************************************\n");
		k++;
	}
	*/
	/*
	int niz[7] = { 2,5,8,7,15,87,67 };
	mergesort(niz, 7);
	print(niz, 7);
	*/

}