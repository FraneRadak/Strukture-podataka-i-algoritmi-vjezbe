#include <stdio.h>

int mystrlen(char* string)
{
	int i;
	for (i = 0;string[i] != '\0';i++)
	{
	}
	return i;
}

void mystrcpy(char* string1, char* string2) {
	int i;
	for (i = 0;string2[i] != '\0';i++)
		string1[i] = string2[i];
	string1[i] = '\0';
}

int mystrcmp(char* string1, char* string2)
{
	int i;
	int broj = mystrlen(string1);
	if (broj < mystrlen(string2))
		broj = mystrlen(string2);
	
	for (i = 0;i<broj;i++)
	{
		if (string1[i] != string2[i])
		{
			{
				if (string1[i] > string2[i])
					return 1;
				else
					return -1;
			}
		}
	}
	return 0;

	
}

int* mystrstr(char* string1, char* string2) {
	int n = mystrlen(string1);
	int m = mystrlen(string2);
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < n && j < m)
	{
		if (string1[i] == string2[j])
		{
			i++;
			j++;
			if (j == m - 1)
			{
				printf("match\n");
				return &string1[i - m + 1];
			}

		}
		else
		{
			k += 1;
			j = 0;
			i = k;
		}
	}
	printf("no match \n");
	return 0;
}

void mystrcat(char* string1, char* string2) {
	int n, j;
	n = mystrlen(string1);
	printf("%d\n");
	printf("%d\n", n);
	for (j = 0;string2[j] != '\0'; j++)
	{
		string1[n + j] = string2[j];
	}
	string1[n + j] = '\0';
}

void reverse(char* string1, char* string2) {

	int n = mystrlen(string1);
	int i;
	int j = 0;
	for (i = n - 1;i >= 0;i--)
	{
		string2[j] = string1[i];
		j++;
	}
	string2[j] = '\0';
}