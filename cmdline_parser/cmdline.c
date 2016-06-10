#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmdline.h"


int get_matching_option(const struct option *longopts, int c)
{
	int i;
	for(i=0;longopts[i].name!=NULL;i++) {
		if(longopts[i].val == c)
			return i;
	}
	return -1;
}

int parse_cmdline(int argc, char **argv, const char* shortopts, 
		struct option *longopts) 
{
	int c;
	struct option *temp;
	int index;

	for(;;) {
		int optindex = -1;
		#ifdef _GNU_SOURCE
			printf("1\n");
			c = getopt_long(argc, argv, shortopts, 
					longopts, &optindex);
		#elif _POSIX_C_SOURCE >= 2
			c = getopt(argc, argv, shortopts);
		#else
			#error "Feature test macro failure.\n"
		#endif
		if(c < 0)
			break;
		switch(c) {
			case 0:
				break;
			case '?':
				fprintf(stderr, "Valid short options: %s\n", shortopts);
				return PARSE_FAILURE;
			default:
				fprintf(stderr, "default, c = %c, %d\n", c, optindex);
				if(optindex < 0)
					index = get_matching_option(longopts, c);
				else
					index = optindex;
				if(index < 0) {
					fprintf(stderr, "Invalid short option, %c\n", c);
					return PARSE_FAILURE;
				}

				if(add_new_option(longopts[index], optarg)) {
					fprintf(stderr, "Error adding new option \n");
					return PARSE_FAILURE;
				}
		};
	}
	return PARSE_SUCCESS;
}

int main(int argc, char *argv[])
{
	struct option longopts[]={
		{"one", required_argument, 0, '1'},
		{"two", required_argument, 0, '2'},
		{"three", required_argument, 0, '3'},
		{"four", required_argument, 0, '4'},
		{0,0,0,0}
	};
	const char* shortopts = "1:2:3:4:";
	
	if(parse_cmdline(argc, argv, shortopts, longopts)
			== PARSE_FAILURE) {
		exit(EXIT_FAILURE);
	}
	return 0;
}
