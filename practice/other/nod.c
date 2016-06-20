#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nod(int num){
	int i;
	i = 0;
	for(;num>0;++i){
		num = num/10;
	}
	return i;
}

int main(int argc, char* argv[]){
	printf("nod = %d\n", nod(atoi(argv[1])));
	return 0;
}
