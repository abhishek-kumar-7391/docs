#include "parse_cmdline.h"

struct parse_cmdline_vars parse_cmd;

int parse_cmdline(int argc, char** argv){
	
	int retcode;
	struct option longopts[]={
		{"iface", required_argument, 0, 'i'},
		{0,0,0,0}
	};
	
	if(argc==1)
		return RET_CMDLINE_PARSE_ERROR;
	
	parse_cmd.longopts = longopts;
	parse_cmd.shortopts = "i:";
	parse_cmd.c = -1;
	
	for(;;){
		int opt_index = -1;
		parse_cmd.c = getopt_long(argc, argv, parse_cmd.shortopts, 
					parse_cmd.longopts, &opt_index);
		if(parse_cmd.c < 0)
			break;
		switch(parse_cmd.c){
			case 'i':
				parse_cmd.iface = strdup(optarg);
#ifdef DEBUG
				fprintf(stdout, "interface = %s\n", parse_cmd.iface);
#endif
				break;
		}
	}
	retcode = RET_SUCCESS;
	return retcode;
}
