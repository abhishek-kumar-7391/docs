#include <stdio.h>
int main(){
	register int p=0;
	fprintf(stdout, "%p\n", &p);
	return 0;
}
