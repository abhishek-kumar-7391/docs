#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <assert.h>
#include <arpa/inet.h>

void usage(void)
{
	fprintf(stderr, "./server SERVER_IP\n");
	exit(EXIT_FAILURE);
}

void err_exit(const char* reason)
{
	perror(reason);
	exit(EXIT_FAILURE);
}


int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in caddr;
	socklen_t sock_len;
	char buff[100];
	char* msg = "hello from client";

	if(argc!=2)
		usage();
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	assert(sock>=0);

	caddr.sin_family      = AF_INET;
	caddr.sin_port        = htons(5000);

	if(inet_pton(AF_INET, argv[1], (void*)&caddr.sin_addr.s_addr)<0)
		err_exit("server ip");
	
	sock_len = sizeof(caddr);
	if(connect(sock, (struct sockaddr*)&caddr, sizeof(caddr))<0)
		err_exit("bind");
	for(;;)
	{
		send(sock, (void*)msg, strlen(msg), 0);
		recv(sock, (void*)buff, 99, 0);
		fprintf(stdout, "> %s\n", buff);
		fprintf(stdout, "> %s\n", msg);
	}
	return 0;
}
