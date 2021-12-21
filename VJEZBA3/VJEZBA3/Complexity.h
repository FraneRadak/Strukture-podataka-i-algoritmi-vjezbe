#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


//T(n)=c+c;
//O(T)=O(1)
int cmpfunc(const void* a, const void* b) {
	int va = *((int*)a);
	int vb = *((int*)b);
	return va - vb;
}
//T(N)=n*c+c*n+c*n+c*n+c*n+c=4*c*n+c
//O(n)
int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n); // n*c
	niz[0] = rand() % 5;// c
	for (int i = 1; i < n; i++) { // c+n*c+n*c+n*c=3n*c+c
		niz[i] = niz[i - 1] + rand() % 5 + 1;
	}
	return niz;
}
//T(N)=c+6*n
//O(n)
void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) { // c+6*n
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
//T(N)=c+c+2*c*n+c*n+c*n*n+c*n*n=c*n+2*c*n*n+c*n+(c*n*n+c*n*n+c*n*n)/2+c+c+c
//O(n*n)
int* presjek(int* niz1, int* niz2, int n, int n2,int*lenght){
	int k = 1; //c
	int* array = (int*)malloc(k * sizeof(int));//c
	for (int i=0;i<n;i++)// c+2*c*n
		for (int j = 0;j < n2;j++)//c*n+c*n*n+c*n*n=c*n+2*c*n*n
		{
			if (niz1[i] == niz2[j])//c*n*n
			{
				k++;//c*n*n/2
				array = (int*)realloc(array, k * sizeof(int));//c*n*n/2
				array[k-2] = niz1[i];//c*n*n/2
			}
		}
	k--;//c
	array = (int*)realloc(array, k * sizeof(int));//c
	*lenght = k;//c
	return array;
}

//T(N)=c+c+c+c+c*n+c*n+n*log2n+c*n+(c*n+c*n*c*n)/2=6c+c*n+c*n+n*log2n+c*n+((c*n+c*n*c*n)/2)
//O(n*logn)
int* presjek_sort(int* niz1, int* niz2, int n, int n2,int*lenght) {
	int k = 1;//c
	int* intersect_sorted = malloc(k * sizeof(int));//c
	//qsort(niz2, n2, sizeof(int), cmpfunc);
	int* rez;//c
	for (int i = 0;i < n;i++) {//c+c*n+c*n
		rez = bsearch((niz1+i), niz2, n2, sizeof(int), cmpfunc);//log2n
		if (rez != NULL) {//c*n+(c*n+c*n*c*n)/2
			intersect_sorted[k - 1] = (*rez);
			k++;
			intersect_sorted = (int*)realloc(intersect_sorted, k * sizeof(int));
		}
		}

	*lenght = k-1;//c
	return intersect_sorted;
	}


