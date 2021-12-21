#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "longnumber.h"
void Put_at_the_end(int number, LongNumber lst) {
	LongNumber novi = (LongNumber)malloc(sizeof(Digit));
	LongNumber tmp = lst;
	novi->z = number;
	novi->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = novi;
}
LongNumber Put_at_the_begin(int number, LongNumber lst) {
	LongNumber novi = (LongNumber)malloc(sizeof(Digit));
	LongNumber temp = lst;
	novi->z = number;
	novi->next = temp;
	return novi;
}
LongNumber Createlist(int number) {
	LongNumber novi = (LongNumber)malloc(sizeof(Digit));
	novi->z = number;
	novi->next = NULL;
	return novi;
}
void check(int* number, int* overflow) {
	if (*number > 9) {
		*overflow = *number / 10;
		*number = *number % 10;
	}
	else
		*overflow = 0;
}
/*********************************************************************************/
LongNumber reverse(LongNumber num) {
	LongNumber prethodni=NULL;
	LongNumber sljedeci=num->next;
	while (num != NULL)
	{
		sljedeci = num->next;
		num->next = prethodni;
		prethodni = num;
		num = sljedeci;
	}
	num = prethodni;
	return num;
}
LongNumber read_longnum(char* fname) {
	LongNumber lst = NULL;
	char c;
	FILE* fp = fopen(fname, "r");
	if (!fp) {
		printf("Cannot open the file\n");
		return 0;
	}
	c = fgetc(fp);
	if (!feof(fp))
		 lst = Createlist((int)c - 48);
	else
		 lst = Createlist(0);
	do {
		 c = fgetc(fp);
		if (feof(fp)) {
			break;
		}
		lst = Put_at_the_begin((int)c - 48, lst);
	} while (1);
	fclose(fp);
	return lst;
}
void print_longnum(LongNumber num) {
	LongNumber temp = reverse(num);
	LongNumber temp2 = temp;
	while (temp != NULL) {
		printf("%d", temp->z);
		temp = temp->next;
	}
	num = reverse(temp2);
	printf("\n");
}
LongNumber add_longnum(LongNumber a, LongNumber b) {
	LongNumber tempa = a->next;
	LongNumber tempb = b->next;
	int overflow = 0;
	int number;
	number = a->z + b->z;
	check(&number, &overflow);
	LongNumber lst = Createlist(number);

	while (tempa != NULL && tempb != NULL) {
		number = tempa->z + tempb->z + overflow;
		check(&number, &overflow);
		Put_at_the_end(number, lst);
		tempa = tempa->next;
		tempb = tempb->next;	
	}
	while (tempa != NULL) {
		number = tempa->z + overflow;
		check(&number, &overflow);
		Put_at_the_end(number, lst);
		tempa = tempa->next;
	}
	while (tempb != NULL) {
		number = tempb->z + overflow;
		check(&number, &overflow);
		Put_at_the_end(number, lst);
		tempb = tempb->next;
	}
	while (overflow) {
		Put_at_the_end(overflow%10, lst);
		overflow = overflow / 10;
	}
	return lst;
}
LongNumber mul_by_digit(LongNumber num, int digit) {
	LongNumber tempnum = num->next;
	int overflow = 0;
	int number;
	number =num->z*digit;
	check(&number, &overflow);
	LongNumber lst = Createlist(number);
	while (tempnum != NULL) {
		number = tempnum->z * digit+overflow;
		check(&number, &overflow);
		Put_at_the_end(number, lst);
		tempnum = tempnum->next;
	}
	while (overflow) {
		Put_at_the_end(overflow%10, lst);
		overflow = overflow / 10;
	}
	return lst;
}
LongNumber mul_by_pow10(LongNumber num, int pow) {
	if (num->z == 0 && num->next == NULL) {
		LongNumber tempnum = Createlist(0);
		return tempnum;
	}
	LongNumber temp =num->next;
	LongNumber tempnum=Createlist(num->z);
	while (temp != NULL) {
		Put_at_the_end(temp->z, tempnum);
		temp = temp->next;
	}
	for (int i = 0;i < pow;i++) {
		tempnum = Put_at_the_begin(0, tempnum);
	}
	return tempnum;
}
LongNumber mul_longnum(LongNumber a, LongNumber b) {
	LongNumber broj = a;
	LongNumber broj2 = b;
	LongNumber rezultat = Createlist(0);
	int counter = 0;
	while (broj2 != NULL) {
		rezultat = add_longnum(mul_by_digit(mul_by_pow10(broj, counter), broj2->z), rezultat);
		counter++;
		broj2 = broj2->next;
	}
	return rezultat;
}
void write_longnum(char* fname, LongNumber num) {
	LongNumber temp = reverse(num);
	LongNumber temp2 = temp;
	FILE* fp = fopen(fname, "w");
	if (!fp)
		printf("Error creating file\n");
	while (temp != NULL) {
		fprintf(fp, "%d", temp->z);
		temp = temp->next;
	}
	fclose(fp);
	num =reverse(temp2);
}

void delete_longnum(LongNumber num) {
	while (num != NULL) {
		LongNumber tmp = num;
		num = num->next;
		free(tmp);
}
}






