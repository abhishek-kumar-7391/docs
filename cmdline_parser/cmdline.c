#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cmdline.h"

int cl_args_count = 0;
cmdline_args *cl_args;

int get_matching_option(const struct option *longopts, int c)
{
	int i;
	for(i=0;longopts[i].name!=NULL;i++) {
		if(longopts[i].val == c)
			return i;
	}
	return -1;
}

static void dump_all_options(void)
{
	int i;
	for(i=0;i<cl_args_count;i++) 
		fprintf(stderr, "opt = %c, arg = %s\n",
			cl_args[i].opts.val, cl_args[i].optarg);
}

static void dump_cl_arg(cmdline_args *cl_args)
{
	fprintf(stderr, "[ Last ] -%c : %s\n", cl_args->opts.val,
			cl_args->optarg);
}

static int add_new_option(const struct option *opt, 
		const char *optarg)
{
	cmdline_args temp; 
	
	temp.opts = *opt;
	temp.optarg = strdup(optarg);
#ifdef DEBUG
	dump_cl_arg(&temp);
#endif
	/* first option */
	if(cl_args_count == 0) {
		cl_args = malloc(sizeof(struct cmdline_args));
	}else 
		cl_args = realloc(cl_args, 
			sizeof(struct cmdline_args) * (cl_args_count + 1));	
		
	if(!cl_args) {
		fprintf(stderr, "Syste out of memory.\n");
		return -ENOMEM;
	}
	cl_args[cl_args_count++] = temp;
#ifdef DEBUG
	fprintf(stderr, "Dumping all options after adding new one: \n");
	dump_all_options();
#endif
	return 0;
}

int parse_cmdline(int argc, char **argv, const char* shortopts, 
		struct option *longopts) 
{
	int c;
	int index;

	for(;;) {
		int optindex = -1;
		#ifdef _GNU_SOURCE
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
				if(optindex < 0)
					index = get_matching_option(longopts, c);
				else
					index = optindex;
				if(index < 0) {
					fprintf(stderr, "Invalid short option, %c\n", c);
					return PARSE_FAILURE;
				}

				if(add_new_option(&longopts[index], optarg) < 0) {
					fprintf(stderr, "Error adding new option \n");
					return PARSE_FAILURE;
				}
		};
	}
	return PARSE_SUCCESS;
}

static int option_exists(int c, const char *name)
{
	int i;
#ifdef DEBUG
	fprintf(stderr, "Checking existence for %c\n", c);
#endif
	if(c >= 0) {
		for(i=0;i<cl_args_count;i++) {
			if(cl_args[i].opts.val == c)
				return i;
		}
	}else if(name) {
		for(i=0;i<cl_args_count;i++) {
			if(!strcmp(cl_args[i].opts.name,name))
				return i;
		}
	}
	return 0;
}

char *go_short(int c)
{
	int index;
	if((index = option_exists(c, NULL)) >=0) 
		return cl_args[index].optarg;		
	return NULL;
}

char *go_long(const char *name)
{
	int index;
	if((index = option_exists(-1, name)) >=0) 
		return cl_args[index].optarg;		
	return NULL;
}

void test_go_short(void)
{
	int i;
	for(i=0;i<cl_args_count;i++) {
		fprintf(stderr, "for %c arg = %s\n", 
			cl_args[i].opts.val, go_short(cl_args[i].opts.val));
	}
}

void test_go_long(void)
{
	int i;
	for(i=0;i<cl_args_count;i++) {
		fprintf(stderr, "arg = %s\n", 
			go_long(cl_args[i].opts.name));
	}
}

