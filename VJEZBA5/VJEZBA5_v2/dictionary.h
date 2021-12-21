#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; 
} Word;

typedef Word* Dictionary;

// kreaira novi prazni rjecnik
Dictionary CreateDictionary();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void Print(Dictionary dict);

// bri�e cijeli rje�nik
void Destroy(Dictionary dict);

Dictionary FilterDicty(Dictionary dict,int(*filter)(Dictionary Word));
Dictionary CreateElement(char* str);
int filter(Word* part);

#endif