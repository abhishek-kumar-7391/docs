#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char* argv[]){
	int rv = -1;

	if(argc==2)
		fprintf(stderr, "argv = %s\n", argv[1]);
	struct addrinfo *addr, hints, *reply, *temp;

	memset(&hints, '\0', sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_flags |= AI_CANONNAME;

	rv = getaddrinfo(NULL, "80", &hints, &reply);
	if(!rv){
		fprintf(stderr, "success\n");
		temp = reply;
		while(temp){
			fprintf(stderr, "server = %s\n", temp->ai_addr->sa_data);
			temp = temp->ai_next;
		}
	}
	return 0;
}
