#include <stdio.h>
#include "b.h"
#include "c.h"

int(*op)(int, int);

int main(void){
	op = add;
	op(2,3);
	op = mul;
	op(2,3);
}
