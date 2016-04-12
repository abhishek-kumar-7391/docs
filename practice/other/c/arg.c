#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	char* line;
	ssize_t ret = 0;
	size_t rd = 0;
	if(getline(&line, &rd, stdin))
		fprintf(stdout, "line = %s\n", line);
	perror("getline");
	getline(&line, &rd, stdin);
	fprintf(stdout, "line = %s\n", line);
	perror("getline");
	return 0;
}
