#include <stdio.h>
#include "strings.h"


void main() {
	/* zadatak1
	char string[] = "abcdefgh";
	printf("String ima %d simbola", mystrlen(string));
	*/


	/*zadatak2
	char string1[25] = "abcde";
	char string2[15] = "edca";
	mystrcpy(string1, string2);
	printf("%s", string1);
	*/

	/*zadatak 3
	int n, m;
	char string1[] = "abx";
	char string2[] = "abc";
	printf("%d", mystrcmp(string1, string2));
	*/
	
	


	/*zadatak 4
	char string1[75] = "abc";
	char string2[15] = "defgh";
	mystrcat(string1, string2);
	printf("%s", string1);
	return 0;
	*/
	

	
	char string[] = "abbabba";
	printf("%p\n", &string[2]);
	char str1[] = "bab";
	printf("%p", mystrstr(string, str1));
	
	
	/*
	char string1[] = "123456";
	char string2[50] = "ghjkloiu";
	int n;
	n = sizeof(string1) / sizeof(string1[0]);
	reverse(string1, string2);
	printf("%s", string2);
	*/
}

