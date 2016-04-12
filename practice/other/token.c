#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char* saveptr = NULL;
	char* temp = NULL;
	if(argc==2){
		temp = strtok_r(argv[1], " ", &saveptr);
		while(temp){
			fprintf(stderr, "temp = %s\n", temp);
			temp = strtok_r(NULL, " ", &saveptr);
		}

		printf("chck\n");
		saveptr = NULL;
		temp = NULL;
		temp = strtok_r(argv[1], " ", &saveptr);
		while(temp){
			fprintf(stderr, "temp = %s\n", temp);
			temp = strtok_r(NULL, " ", &saveptr);
		}
	}
}
