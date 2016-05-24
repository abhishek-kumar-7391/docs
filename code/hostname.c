#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char buf[100];
	size_t len = 100;
	if(gethostname(buf, len)){
		perror("gethostname");
		exit(EXIT_FAILURE);
	}else
		fprintf(stderr, "Hostname = %s\n", buf);
	return 0;
}
