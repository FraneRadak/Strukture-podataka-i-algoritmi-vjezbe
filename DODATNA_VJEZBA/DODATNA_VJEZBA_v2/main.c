#include "longnumber.h"

void main() {
	LongNumber numa = read_longnum("a.txt");
	print_longnum(numa);
	LongNumber numb = read_longnum("b.txt");
	print_longnum(numb);



	printf("--------------------------------\n");
	LongNumber numc = add_longnum(numa, numb);
	print_longnum(numc);
	write_longnum("add_longnum.txt", numc);
	printf("---------------------------\n");
	LongNumber numd = mul_by_digit(numc, 9);
	print_longnum(numd);
	write_longnum("mul_by_digit.txt", numd);
	printf("---------------------------\n");
	LongNumber nume = mul_by_pow10(numd, 3);
	print_longnum(nume);
	write_longnum("mul_by_pow10.txt", nume);
	printf("---------------------------\n");
	LongNumber numf = mul_longnum(numa, numb);
	print_longnum(numf);
	write_longnum("mul_longnum.txt", numf);
	printf("--------------------------------------\n");



	printf("Data entry successful\n");
	printf("--------------------------------------\n");


	
	delete_longnum(numa);
	delete_longnum(numb);
	delete_longnum(numc);
	delete_longnum(numd);
	delete_longnum(nume);
	delete_longnum(numf);
	printf("All data deleted\n");
	printf("END //");
}