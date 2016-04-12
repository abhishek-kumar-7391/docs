#include <stdio.h>
#include <stdint.h>
int main(int argc, char*argv[]){
	char* end;
	uint64_t num = strtoll(argv[1], &end, 16);
	fprintf(stdout, "num = %lu\n", num);
	return 0;

}
