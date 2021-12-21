#include <stdio.h>
#include <malloc.h>

typedef struct {
	float x;
	float y;
}TOCKA;
typedef struct {
	TOCKA* vrhovi;
	int n;
}POLIGON;
//zadatak1
//*************************************************************

int* podniz(int* niz, int start, int stop) {
	int k = 0;
	if (stop <= start)
		return 0;
	int* p = (int*)malloc((stop - start + 1) * sizeof(int));
	if (p == NULL) {
		printf("Memmory is not allocated");
		return 0;
	}
	else
		printf("Memmory successfully allocated\n");
	printf("*****************\n");
	printf("\n");
	for (int i = start - 1;i < stop;i++) {
		p[k] = niz[i];
		k++;
	}
	return p;
}
	//***************************************************************
	//zadatak2
int* filtriraj(int* niz, int n, int th, int* nth) {
	int k = 0;
	int lenght = 0;
	int* p1 = (int*)malloc(lenght * sizeof(int));
	for (int i=0;i<n;i++)
	{
		if (niz[i] < th)
		{
			lenght += 1;
			p1 = (int*)realloc(p1, lenght*sizeof(int));
			p1[k] = niz[i];
			k++;
		}		
	}
	*nth = lenght;
	return p1;
}
//*********************************************************************
//zadatak 4
int** podijeli(int* niz, int n) {
	int j = 0;
	int k = 0;
	int** result = (int**)malloc(2 * sizeof(int*));
	int* podniz1 = (int*)malloc(((n / 2)) * sizeof(int));
	int* podniz2 = (int*)malloc((n - (n / 2)) * sizeof(int));
	if (podniz1 != NULL && podniz2 != NULL)
		printf("Memmory successfully allocated\n");
	printf("******************\n");

	for (int i = 0;i < n;i++) {
		if (i < n / 2)
		{
			podniz1[j] = niz[i];
			j++;
		}
		else {
			podniz2[k] = niz[i];
			k++;
		}
	}
	result[0] = podniz1;
	result[1] = podniz2;
	return result;
}
//******************************************************************
//zadatak 5
	POLIGON* NoviPoligon(float* niz_x, float* niz_y, int n) {
		POLIGON* ptr = (POLIGON*)malloc(sizeof(POLIGON));
		ptr->vrhovi =(TOCKA*) malloc(sizeof(TOCKA) * n);
		ptr->n = n;
		for (int i = 0;i < n;i++)
		{
			ptr->vrhovi[i].x = niz_x[i];
			ptr->vrhovi[i].y = niz_y[i];
		}
		return ptr;
	}
	//***********************************************************************
	//zadatak 6
	TOCKA** Pozitivni(POLIGON* p, int* np) {
		TOCKA** ptr = (TOCKA**)malloc(*np * sizeof(TOCKA*));
		for (int i = 0;i < p->n;i++) {
			if (p->vrhovi[i].x >= 0 && p->vrhovi[i].y >= 0)
			{
				*np+=1;
				ptr = (TOCKA**)realloc(ptr, *np * sizeof(TOCKA*));
				ptr[*np - 1] = p->vrhovi + i;
			}
		}
		return ptr;
	}
	//******************************************************************************







