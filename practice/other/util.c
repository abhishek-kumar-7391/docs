#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc!=2){
		fprintf(stderr, "Invalid Arguments !!");
		exit(EXIT_FAILURE);
	}
	int i;

	char* temp;
	temp=malloc(strlen(argv[1])+2);
	strncpy(temp, argv[1],strlen(argv[1]));
	argv[1] = temp;
	for(i=0;i<3;++i)
		temp = strchr(temp, '.')+1;
	sprintf(temp, "%s", "255");
	fprintf(stdout, "%s", argv[1]);
}
