#include <stdio.h>
#include <stdlib.h>

int a __attribute__ ((section ("DUART_A"))) = { 0 };
int b __attribute__ ((section ("DUART_B"))) = { 0 };
char stack[10000] __attribute__ ((section ("STACK"))) = { 0 };
int init_data __attribute__ ((section ("INITDATA")));


int old_var __attribute__ ((deprecated));

int new_fn () { 

	return old_var; 
}

int main(int argc, char* argv[])
{

	new_fn();
}
