#ifndef CMDLINE
#define CMDLINE

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <getopt.h>

#define ERRBUF_SIZE 1024
#define PARSE_FAILURE 1
#define PARSE_SUCCESS 0

typedef struct cmdline_args {
	struct option opts;
	char *optarg;
} cmdline_args;

extern int cl_args_count;
extern cmdline_args *cl_args;
#endif
