#ifndef PARSE_CMDLINE
#define PARSE_CMDLINE

#include "common.h"

#define OPTIONS_SIZE 10

int parse_cmdline(int, char**);

struct parse_cmdline_vars{
	const char* iface;
	struct option* longopts;
	const char* shortopts;
	int c;
};

extern struct parse_cmdline_vars parse_cmd;

#endif
