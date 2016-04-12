#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <net/if.h> /* struct ifreq.h */
#include <sys/ioctl.h> /* for SIOCGIFINDEX */
#define print_int(name) fprintf(stdout, "%s = %d\n", #name, name);
#define print_str(name) fprintf(stdout, "%s = %s\n", #name, name);


int main(int argc, char* argv[])
{
	struct ifreq ifr;
	const int on = 1;
	int dev_index;
	char* dev; /* default device */
	char src_ip[INET_ADDRSTRLEN];
	char dst_ip[INET_ADDRSTRLEN];
	struct addrinfo dst_info; /* for getaddrinfo */
	struct addrinfo *result;
	struct sockaddr_in sin;
	if(argc<2)
		dev = "eth0";
	else if(argc==2)
		dev = argv[1];
	else{
		fprintf(stderr, "Invalid arguments!\n");
		exit(EXIT_FAILURE);
	}
	/* get socket to find device index */
	int fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	print_int(fd);
	if(fd<0){
		perror("socket");
		return -1;
	}

	strcpy(ifr.ifr_name, dev);
	print_str(ifr.ifr_name);

	/* now find the index of the device */
	if(ioctl(fd, SIOCGIFINDEX, &ifr)<0){
		perror("device index");
		exit(EXIT_FAILURE);
	}
	print_int(ifr.ifr_ifindex);
	close(fd); /* got the device index, socket no longer required */
	print_int(INET_ADDRSTRLEN);
	memset(src_ip, '\0', INET_ADDRSTRLEN);
	memset(dst_ip, '\0', INET_ADDRSTRLEN);
	strcpy(src_ip, "172.16.1.35");
	strcpy(dst_ip, "127.0.0.1");
	print_str(src_ip);	
	print_str(dst_ip);	

	/* get info about the destination */
	memset(&dst_info, 0, sizeof(dst_info));
	dst_info.ai_family   = AF_INET;
	dst_info.ai_socktype = SOCK_STREAM;
	if(getaddrinfo(dst_ip, NULL, &dst_info, &result)){
		perror("getaddrinfo");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "check1\n");
	/* set the ip header */
	struct icmp icmphdr;
	int ICMP_HDRLEN = 8;
	memset(&icmphdr, 0, sizeof(struct icmp));
	icmphdr.icmp_type = ICMP_ECHO;
	icmphdr.icmp_id   = htons((short)getpid());
	fprintf(stdout, "check2\n");

	/* set the ipv4 header */
	struct ip iphdr;
	iphdr.ip_hl = 5; /* ip header length */
	iphdr.ip_v  = 4;
	iphdr.ip_tos= 2;
	iphdr.ip_len=20+8;
	iphdr.ip_p  = IPPROTO_ICMP;
	iphdr.ip_ttl= 63;
	if(inet_pton(AF_INET, src_ip, &(iphdr.ip_src))<0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "check3\n");
	if(inet_pton(AF_INET, dst_ip, &(iphdr.ip_dst))<0){
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "check4\n");
	uint8_t* packet = malloc(IP_MAXPACKET);
	memcpy(packet,&iphdr, 20);
	fprintf(stdout, "check5\n");
	memcpy((packet+20),&icmphdr, ICMP_HDRLEN);
	fprintf(stdout, "check6\n");
	memset(&sin, '\0', sizeof(struct sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = iphdr.ip_dst.s_addr;
	fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if(fd<0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	print_int(fd);
	/* user is to specify the ip headers */
	if(setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on))<0){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "check7\n");
	/* bind socket to interface index */
	if(setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr))<0){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "check8\n");
	int i;
	//for(i=0;i<10;++i){
		if(sendto(fd, packet, 20+ICMP_HDRLEN, 0, (struct sockaddr*)&sin, sizeof(struct sockaddr))<0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}
	//}
	
	memset(packet, '\0', IP_MAXPACKET);
	if(recvfrom(fd, packet, IP_MAXPACKET, 0,(struct sockaddr *)&sin, sizeof(struct sockaddr)<0)){
		perror("recvfrom");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return 0;
}
