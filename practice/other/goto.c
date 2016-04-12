#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main(int argc, char* argv[]){
	
	int a;
	a = 4;
print:
	printf("a = %d\n", a);

	a = 10;
	goto print;
	return 0;
}
