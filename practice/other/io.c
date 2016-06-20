#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char* path="/home/test/radvd/test";
	FILE* fp;
	int i;
	fp = fopen(path, "r+");
	if(!fp)
		exit(-1);
	for(i = 0; i<1000;++i)
		fprintf(fp, "%c", 'a');
	return 0;
}
