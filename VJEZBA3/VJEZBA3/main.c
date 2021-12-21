#include "Complexity.h"


int lenght;
int n = 30000;
int n2 = 10000;
void main(void){

	srand((unsigned int)time(NULL));
	/*
	for (int i = 0;i < 8;i++) {
		int* pointer = generiraj(n);
		int* pointer2 = generiraj(n2);
		int start = clock();
		int*niz3=presjek(pointer, pointer2, n, n2, &lenght);
		int stop = clock();
		printf("TIME %d : %lf\n",i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		n2 += 5000;
	}
	printf("***************************************************\n");
	 n = 10000;
	 n2 = 30000;
	for (int i = 0;i < 8;i++) {
		int* pointer = generiraj(n);
		int* pointer2 = generiraj(n2);
		int start = clock();
		int*niz3=presjek(pointer, pointer2, n, n2, &lenght);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		n += 5000;
	}
	*/
	
	/*
	for (int i = 0;i < 8;i++) {
		int* pointer = generiraj(n);
		int* pointer2 = generiraj(n2);
		qsort(pointer2, n2, sizeof(int), cmpfunc);
		int start = clock();
		int*niz3=presjek_sort(pointer, pointer2, n, n2, &lenght);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		n2 += 5000;
	}
	printf("**********************************************\n");
	 n = 10000;
	 n2 = 30000;
	for (int i = 0;i < 8;i++) {
			int* pointer = generiraj(n);
			int* pointer2 = generiraj(n2);
			qsort(pointer2, n2, sizeof(int), cmpfunc);
			int start = clock();
			int *niz3=presjek_sort(pointer, pointer2, n, n2, &lenght);
			int stop = clock();
			printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
			n += 5000;
	}
	*/
	
	/*
	for (int i = 0;i < 8;i++) {
		int* pointer = generiraj(n);
		int* pointer2 = generiraj(n2);
		int start = clock();
		qsort(pointer2, n2, sizeof(int), cmpfunc);
		int *niz3=presjek_sort(pointer, pointer2, n, n2,&lenght);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		n2 += 5000;
	}
	printf("**********************************************\n");
	n = 10000;
	n2 = 30000;
	for (int i = 0;i < 8;i++) {
		int* pointer = generiraj(n);
		int* pointer2 = generiraj(n2);
		int start = clock();
		qsort(pointer2, n2, sizeof(int), cmpfunc);
		int* niz3 = presjek_sort(pointer, pointer2, n, n2, &lenght);
		int stop = clock();
		printf("TIME %d : %lf\n", i, ((double)(stop - start)) / CLOCKS_PER_SEC);
		n += 5000;
	}
	*/
	int* pointer = generiraj(5);
	int* pointer2 = generiraj(5);
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", pointer[i]);
	}
	printf("\n");
	for (int i = 0;i < 5;i++)
	{
		printf("%d ", pointer2[i]);
	}


}