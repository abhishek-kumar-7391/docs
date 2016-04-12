#include <stdio.h>

int main(int argc, char* argv[]){
	char* endptr;
	strtol(argv[1], &endptr, 16);
	if(*endptr){
		fprintf(stderr, "invalid string\n");
	}else
		printf("valid integer\n");

}
