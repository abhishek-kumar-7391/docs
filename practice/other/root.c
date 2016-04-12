#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

int uid;
int gid;

static int drop_root(int uid, int gid){
	if(getuid()==0){
		fprintf(stdout, "Running as root\n");
		fprintf(stdout, "Dropping root previlige..\n");
		if(setuid(uid) || setgid(gid)){
			fprintf(stderr, "Error dropping root prevlige.\n");
			perror("setuid");
			perror("setgid");
			return -1;
		}
	}else
		fprintf(stdout, "Not running as root.\n");
	return 0;
}

int main(int argc, char* argv[]){
	int c;
	static struct option long_options[]={
		{"uid", required_argument, 0, 'u'},
		{"gid", required_argument, 0, 'g'},
		{0,0,0,0}
	};
	
	const char* longopts="u:g:";

	fprintf(stdout, "userid = %d, gid = %d", getuid(), getgid());
	c = uid = gid = -1;
	while(1){
		int option_index;
		c = getopt_long(argc, argv, longopts, 
				long_options, &option_index);
		if(c<0)
			break;
		switch(c){
			case 'u':
				uid = atoi(optarg);
				break;
			case 'g':
				gid = atoi(optarg);
				break;
		}
	}
	fprintf(stdout, "gid = %d, uid = %d\n", gid, uid);
	return drop_root(uid, gid);
}
