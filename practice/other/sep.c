#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	const char* sep = NULL;

	//sep = strchr(argv[1], '-') || strchr(argv[1], '/');
	
	sep =  (strchr(argv[1], '-'))? strchr(argv[1], '-'): strchr(argv[1], '/');

	printf("sep = %c\n", *sep);
	return 0;
}
