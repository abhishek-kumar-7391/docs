#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/netlink.h>

int main(int argc, char *argv[]) {
	int fd = -1;
	struct sockaddr_nl nl_sock;
	struct msghdr msg;
	struct sockaddr_nl dest;
	struct nlmsghdr *nlh;
	struct iovec iov;

	memset(&msg, '\0', sizeof (struct msghdr));
	memset(&dest, '\0', sizeof (struct sockaddr_nl));
	memset(&nl_sock, '\0', sizeof (struct sockaddr_nl));
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
	dest.nl_family = AF_NETLINK;
	/* if the message is for another process, not the kernel, then pid should be 
	 * other process's pid and groups should be 0 */
	dest.nl_pid = 0; // should be a unique 32 bit integer 
	dest.nl_groups = 0; // to recieve messages only for the given protocol type; unicast

	nlh = (struct nlmsghdr*)malloc(NLMSG_SPACE(MAX_PAYLOAD));
	memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
	nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
	nlh->nlmsg_pid = getpid();
	nlh->nlmsg_flags = 0;
	iov.iov_base = (void *)nlh;
	iov.iov_len = nlh->nlmsg_len;
	return 0;
}
