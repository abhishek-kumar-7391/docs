#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char* str){
	fprintf(stdout, "str = %s\n", str);
}

int main(int argc, char* argv[]){

char* str = argv[1];
char* temp;
char* saveptr;
	fprintf(stdout, "hello\n");
	temp = strtok_r(str, ".", &saveptr);
	fprintf(stdout, "str = %s\n", str);
	if(!temp){
		fprintf(stderr, "temp is null\n");
	}
	print(str);
	print(saveptr);

return 0;
}
