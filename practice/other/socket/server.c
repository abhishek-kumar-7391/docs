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
	int acc_fd;
	char* msg = "hello from server";

	sock = socket(AF_INET, SOCK_STREAM, 0);
	assert(sock>=0);

	caddr.sin_family      = AF_INET;
	caddr.sin_port        = htons(5000);
	caddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sock_len = sizeof(caddr);
	if(bind(sock, (struct sockaddr*)&caddr, sizeof(caddr))<0)
		err_exit("bind");
	if(listen(sock, 5)<0)
		err_exit("listen");
	fprintf(stdout, "server waits:\n");
	acc_fd = accept(sock, (struct sockaddr*)&caddr,&sock_len);
	for(;;)
	{
		memset(buff, '\0', sizeof(buff));
		//recv(acc_fd,(void*)buff, 50);
		fprintf(stdout, "%s\n", buff);
		/*scanf("%s", buff);
		write(acc_fd, buff, strlen(buff));
		fprintf(stdout, "%s\n", buff);*/
	}
	return 0;
}
