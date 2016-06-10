#include <stdio.h>
#include <stdlib.h>
#include "cmdline.h"
int main(int argc, char *argv[])
{
	char *arg = NULL;
	struct option longopts[] = {
		{"one", required_argument, 0, '1'},
		{"two", required_argument, 0, '2'},
		{"three", required_argument, 0, '3'},
		{"four", required_argument, 0, '4'},
		{0,0,0,0}
	};
	const char* shortopts = "1:2:3:4:";
	
	if(parse_cmdline(argc, argv, shortopts, longopts) == PARSE_FAILURE) {
		exit(EXIT_FAILURE);
	}
	arg = go_short(1);
	if(arg)
		fprintf(stderr, "arg = %s\n", arg);
	arg = go_long("one");
	if(arg)
		fprintf(stderr, "arg = %s\n", arg);

	return 0;
}
