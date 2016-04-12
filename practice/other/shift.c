#include <stdio.h>

int main(void)
{
	volatile unsigned char mask = 3;
	volatile unsigned char value = 2;
	volatile unsigned char as = 0;
	mask = (mask<<7);
	mask = mask>>7;
	value = value<<7;
	value = value>>7;
	fprintf(stdout, "mask = %u\n", mask);
	fprintf(stdout, "value = %u\n", value);
	as =  mask | value;
	fprintf(stdout, "as = %d\n", as);

	volatile unsigned char a = 3;
	fprintf(stdout, "a = %d\n", a);
	a = a<<7;
	fprintf(stdout, "a = %d\n", a);
	a = a>>7;
	fprintf(stdout, "a = %d\n", a);

}
