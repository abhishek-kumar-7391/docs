#include <stdio.h>
int main(){
	int num = 0xf0;
	fprintf(stderr, "com = %.2x\n", ~num);
}
