#include <stdio.h>
#include "arrays.h"
#include <malloc.h>
#include <ctype.h>
#include <time.h>



void main(void) {
	/*
	int niz[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int start = 2;
	int stop = 5;
	int* ptr = podniz(niz, start, stop);
	if (ptr != NULL)
	{
		for (int i = 0;i < stop-start+1;i++)
			printf("%d ", ptr[i]);
	}
	else
		printf("ERROR");
	free(ptr);
	*/

	/*
	int niz[] = { 3,4,5,6,7,8 };
	int nth = 0;
	int th = 7;
	int n = sizeof(niz) / sizeof(int);
	int* ptr1= filtriraj(niz, n, th, &nth);
	
	for (int i = 0;i < nth;i++)
		printf("%d ", ptr1[i]);
	free(ptr1);
	*/

	/*zadatak 3
	int niz[] = { 1,2,3,4,5,6 };
	int n = sizeof(niz) / sizeof(int);
	int**result=podijeli(niz,n);
	//provjera
	int* a = result[0];
	int* b = result[1];
	for (int i = 0;i < n / 2;i++)
		printf("%d ", a[i]);
	for (int i = 0;i < n / 2;i++)
		printf("%d ", b[i]);
		
	for (int i = 0;i <= 1;i++)
	{
		free(result[i]);
	}
	free(result);
	*/

	/*zadatak 4,5,6
	float niz_x[] = { 1,-2,3,4,-5,6,7 };
	float niz_y[] = { 1,2,3,4,-5,6,-7 };
	int np = 0;
	
	int n = sizeof(niz_x) / sizeof(float);
	POLIGON* pointer = NoviPoligon(niz_x, niz_y, n);
	for (int i = 0;i < n;i++)
	{
		printf("%f %f\n", pointer->vrhovi[i].x, pointer->vrhovi[i].y);
	}
	TOCKA** ptr2 = Pozitivni(pointer, &np);
	for (int i = 0;i < np;i++) {
		printf("%p\n", ptr2[i]);
	}
	free(pointer->vrhovi);
	free(pointer);
	free(ptr2);
	*/


}