#include <stdio.h>	
#include <string.h>

int main(int argc, char* argv[]){

char* str;
	str = strtok(argv[1], ".");
		fprintf(stdout, "str = %s\n", str);
	while((str = strtok(NULL, "."))!=NULL){
		fprintf(stdout, "str = %s\n", str);
	//	str = strtok(NULL, ".");
	//	fprintf(stdout, "str = %s\n", str);
	//	++argv[1];
	}

return 0;
}
