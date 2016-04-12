#include "sniffer.h"
#include "parse_cmdline.h"

unsigned char* junk="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaas";
static void print_ethernet_header(unsigned char* Buffer, int Size)
{
	struct ethhdr *the = (struct ethhdr *)Buffer;
	FILE* logfile = stdout;
//	if(the->h_proto!=8){
//		Buffer = junk;	
//	}
	fprintf(logfile , "\n");
	fprintf(logfile , "Ethernet Header\n");
	fprintf(logfile , "   |-Destination Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", the->h_dest[0] , the->h_dest[1] , the->h_dest[2] , the->h_dest[3] , the->h_dest[4] , the->h_dest[5] );
	fprintf(logfile , "   |-Source Address      : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", the->h_source[0] , the->h_source[1] , the->h_source[2] , the->h_source[3] , the->h_source[4] , the->h_source[5] );
	fprintf(logfile , "   |-Protocol            : %u \n",(unsigned short)the->h_proto);
}


static void dump_data(unsigned char* data){
	int i;
	i = 0;
	if(!data)
		return;
	fprintf(stdout,"data = \n");
	while(data[i]){
		fprintf(stdout, "%c", data[i]);
		++i;
	}
}


static inline void print_ip_packet(unsigned char* packet, int size){
	struct iphdr* ip;
	unsigned char* data;
	ip = (struct iphdr*)(packet + sizeof(struct ethhdr));
	fprintf(stdout, "ip protocol = %d\n", ip->protocol);
	fprintf(stdout, "saddr = %u\n", ip->saddr);
	fprintf(stdout, "daddr = %u\n", ip->daddr);
	if(ip->protocol == IPPROTO_TCP){
		fprintf(stdout, "tcp packet\n");
		data = packet + sizeof(struct ethhdr) + sizeof(struct iphdr) + sizeof(struct tcphdr);
		dump_data(data);
	}else if(ip->protocol == IPPROTO_UDP){
		fprintf(stdout, "udp packet\n");
		data = packet + sizeof(struct ethhdr) + sizeof(struct iphdr) + sizeof(struct udphdr);
		dump_data(data);
	}
}


static inline void process_packet(unsigned char* packet, int packet_size){
	fprintf(stdout, "packet size = %d\n", packet_size);
	print_ethernet_header(packet, packet_size);
	print_ip_packet(packet, packet_size);
	printf("\n\n");
}


int main(int argc, char* argv[]){
	int retcode;
	int saddr_size , data_size;
	struct sockaddr saddr;

	retcode = parse_cmdline(argc, argv);
	if(retcode == RET_FAILURE){
		fprintf(stderr, "Command line parsing failure\n");
		goto done;
	}

	int sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if(sock_fd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	unsigned char *buffer = (unsigned char *) malloc(65536);
	while(1)
	{
		saddr_size = sizeof saddr;
		data_size = recvfrom(sock_fd , buffer , 65536 , 0 , &saddr , (socklen_t*)&saddr_size);
		if(data_size <0 )
		{
			printf("Recvfrom error , failed to get packets\n");
			return 1;
		}
		//strcpy((char*)buffer+sizeof(struct ethhdr) + sizeof(struct iphdr), (char*)junk);
		process_packet(buffer , data_size);
	}
	// get a raw packet socket
	// start capturing traffic from the interface
	// process the packets captured
done:
	return retcode;
}
