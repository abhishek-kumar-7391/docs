#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
/* to write a method to read and write from the socket */




int server(int portno){
	int sockfd, port;
	struct sockaddr_in server_sock;
	uint32_t addr = 0;
	socklen_t size = sizeof(struct sockaddr_in);
	
	sockfd = -1;
	port = 5555;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	bzero((char*)&server_sock, sizeof(struct sockaddr_in));
#ifdef DEBUG
	fprintf(stderr, "port num = %d\n", port);
#endif
	server_sock.sin_family = AF_INET;
	server_sock.sin_port = htons(port);
	server_sock.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*) &server_sock, size)<0){
		perror("bind");
		exit(EXIT_FAILURE);
	}


}


int client(int portno, const char* server_addr){
	int sockfd;
	struct sockaddr_in server_sock;
	uint32_t addr = 0;
	
	sockfd = -1;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	server_addr = (server_addr)? server_addr:"172.16.1.35";
	bzero((char*)&server_sock, sizeof(struct sockaddr_in));

	server_sock.sin_family = AF_INET;
	server_sock.sin_port = htons(portno);
	if(!inet_aton(server_addr, (struct in_addr*)&addr)){
		perror("server addr");
		exit(EXIT_FAILURE);
	}
	server_sock.sin_addr.s_addr = htonl(addr);
	/* connect to the server */
	if(connect(sockfd, (struct sockaddr*)&server_sock, 
			sizeof(struct sockaddr_in))<0){
		perror("Connection Failure");
		exit(EXIT_FAILURE); // can retry but not now
	}

	fprintf(stderr, "Connected to server...\n");

#ifdef DEBUG
	fprintf(stderr, "server addr = %s, port = %d\n",
			server_addr, portno);
#endif
}


int main(int argc, char* argv[]){
	
	fprintf(stderr, "argv1 = %s\n", argv[1]);
	if(!strcmp(argv[1], "client"))
		client(atoi(argv[3]), argv[2]);
	else if(!strcmp(argv[1], "server"))
		server(atoi(argv[2]));
	return 0;
} 
