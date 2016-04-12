#include <stdio.h>
static int nptme(int num, void* val){
	int* ss = val;
	fprintf(stdout, "num = %d\n", num);
}
int main(void){
	if(on_exit(nptme, 123)){
		fprintf(stderr, "Failed to register!\n");
		exit(-1);
	}
	return 0;
}
