#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#define _GNU_SOURCE

int main(void)
{
	struct utsname host_info = {0};
	if(uname(&host_info)){
		perror("uname");
		exit(EXIT_FAILURE);
	}else {
//		fprintf(stderr, "Host details: \n");
		fprintf(stderr, "System    : %s\n", host_info.sysname); 
		fprintf(stderr, "Release   : %s\n", host_info.release);
		fprintf(stderr, "Version   : %s\n", host_info.version);
		fprintf(stderr, "Machine   : %s\n", host_info.machine);
		fprintf(stderr, "User      : %s\n", host_info.nodename);
	}
	return 0;
}
