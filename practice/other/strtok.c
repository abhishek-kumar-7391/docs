#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char* str){
	fprintf(stdout, "str = %s\n", str);
}

int main(int argc, char* argv[]){

char* str = argv[1];
char* temp;
	fprintf(stdout, "hello\n");
	temp = strtok(str, ".");
	if(!temp){
		fprintf(stderr, "temp is null\n");
	}
	print(str);

return 0;
}
