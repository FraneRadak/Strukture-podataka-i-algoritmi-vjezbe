#include "prioritetni_red.h"

void main(void) {
	int n = 0;
	srand(time(0));
	PRIORITETNI_RED* pr = create(5000);


	insert(pr, 1);
	insert(pr, 5);
	insert(pr, 15);
	insert(pr, 3);
	insert(pr, 78);
	insert(pr, 4);
	insert(pr, 93);

	/*
	//insert(pr, 65);
	insert(pr,2);
	insert(pr, 56);
	//insert(pr, 21);
	insert(pr, 4);
	//insert(pr, 543);
	//insert(pr, 321);
	//insert(pr, 981);
	//insert(pr, 39);
	*/
	ispis(pr);
}