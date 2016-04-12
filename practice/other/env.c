#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	fprintf(stderr, "user = %s\n", getenv(argv[1]));
}
