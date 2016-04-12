#include <stdio.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	uint64_t nbo;
	uint64_t hbo;
	char* endptr;
	if(argc!=2)
	{
		fprintf(stderr, "Invalid args!\n");
		exit(EXIT_FAILURE);
	}

	nbo = strtol(argv[1], &endptr, 10);
	if(*endptr!='\0')
	{
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	hbo = (uint64_t)ntohs((uint16_t)nbo);
	fprintf(stdout, "nbo = %ld\n", nbo);
	fprintf(stdout, "hbo = %ld\n", hbo);

	
}
