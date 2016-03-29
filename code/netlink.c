#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/netlink.h>

int main(int argc, char *argv[]) {
	int fd = -1;
	struct sockaddr_nl nl_sock;
	struct msghdr msg;

	memset(&msg, '\0', sizeof (struct msghdr));
	fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_NETFILTER);
	if(fd < 0){
		perror("socket");
		exit (EXIT_FAILURE);
	}
	nl_sock.nl_family = AF_NETLINK;
	nl_sock.nl_pad = 0;
	/* if the message is for another process, not the kernel, then pid should be 
	 * other process's pid and groups should be 0 */
	nl_sock.nl_pid = getpid(); // should be a unique 32 bit integer 
	nl_sock.nl_groups = 0; // to recieve messages only for the given protocol type; unicast
	if(bind(fd, (struct sockaddr*)&nl_sock, sizeof(nl_sock)) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	msg.msg_name = (void*)&nl_sock;
	msg.msg_namelen = sizeof (nl_sock);
	return 0;
}
