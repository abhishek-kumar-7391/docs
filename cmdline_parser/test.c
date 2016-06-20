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
		{"five", required_argument, 0, '5'},
		{"six", required_argument, 0, '6'},
		{0,0,0,0}
	};
	const char* shortopts = "1:2:3:4:5:6:";
	
	if(parse_cmdline(argc, argv, shortopts, longopts) == PARSE_FAILURE) {
		exit(EXIT_FAILURE);
	}
	arg = go_short('6');
	if(arg)
		fprintf(stderr, "arg = %s\n", arg);
	arg = go_long("five");
	if(arg)
		fprintf(stderr, "arg = %s\n", arg);

	return 0;
}
