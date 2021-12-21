#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Dictionary CreateElement(char* str) {
	Dictionary novi = (Dictionary)malloc(sizeof(Word));
	novi->word =strdup(str);
	novi->count = 1;
	novi->next = NULL;
	return novi;
}
//***************************************************
Dictionary CreateDictionary(){
	Dictionary dicty = (Dictionary)malloc(sizeof(Word));
	dicty->word = "";
	dicty->count = 0;
	dicty->next = NULL;
	return dicty;
}
void add(Dictionary dict, char* str) {
	Dictionary temp=dict;
	while (temp != NULL) {
		if (!(strcmp(temp->word, str))){
			temp->count += 1;
			break;
		}
		else if (temp->next == NULL) {
			Dictionary novi = CreateElement(str);
			novi->next = temp->next;
			temp->next = novi;
			break;
		}
		else if ((strcmp(str, temp->word)) && (strcmp(str, temp->next->word) < 0)) {
			Dictionary novi = CreateElement(str);
			novi->next = temp->next;
			temp->next = novi;
			break;
		}
		temp = temp->next;
	}
}
void Print(Dictionary dict) {
	Dictionary temp = dict->next;
	while (temp != NULL) {
		printf("%s         %d\n", temp->word, temp->count);
		temp = temp->next;
	}
}
int filter(Word* part) {
	if ((part->count > 5 && part->count < 10) && (strlen(part->word) > 3))
		return 1;
	else
		return 0;
}
Dictionary FilterDicty(Dictionary dict,int(*filter)(Dictionary word)) {
	Dictionary temp1 = dict;
	Dictionary temp2 = dict->next;

	while (temp2 != NULL) {
		if (filter(temp2))
		{
			temp1 = temp2;
			temp2 = temp2->next;
		}
		else
		{
			temp2 = temp2->next;
			free(temp1->next->word);
			free(temp1->next);
			temp1->next = temp2;
		}
	}
	return dict;
}
void Destroy(Dictionary dict)
{
	Dictionary temp = dict->next;
	free(dict);
	while (temp != NULL) {
		Word* tmp = temp;
		temp = temp->next;
		free(tmp->word);
		free(tmp);
	}
}


