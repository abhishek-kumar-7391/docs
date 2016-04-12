
#include "cvm.h"

int mode;
int mcast;
int resv;
uint8_t octets[4];

// int ipv4_validation(int argc, char** argv)
// {
// 	int retval;
// 	retval = -1;	

// 	/* perform basic validation, valid address */
// 	retval = test_ipv4(argv[argc-1]);

// 	fprintf(stdout, "ipv4 retval = %d\n", retval);
// done : 
// 	return retval;
// }

// int subnet_validation(int argc, char** argv)
// {

// 	int retval;
// 	retval = -1;	

// 	/* perform basic validation, valid address */
// 	retval = test_subnet(argv[argc-2], argv[argc-1]);
// 	fprintf(stdout, "subnet retval = %d\n", retval);
// done : 
// 	return retval;

// }

// int range_validation(int argc, char** argv)
// {

// 	int retval;
// 	retval = -1;	

// 	/* perform basic validation, valid address */
// 	retval = test_range(argv[argc-2], argv[argc-1]);
// 	fprintf(stdout, "range retval = %d\n", retval);
// done : 
// 	return retval;

// }

void cvm_help(void)
{
	fprintf(stdout, "\nUsage : \n");
	fprintf(stdout, "ipval --ipv4 IP_ADDRESS  [--nomulticast] [--noreserved]\n");
	fprintf(stdout, "ipval --range IP_START IP_END [--nomulticast] [--noreserved]\n");
	fprintf(stdout, "ipval --subnet SUBNET_IP SUBNET_MASK [--nomulticast] [--noreserved]\n\n");
}



int ipval(int argc, char** argv){
	int retval;

	retval = -1;
	if(mode<=0){
		#ifdef DEBUG
		fprintf(stderr, "Mode not specified !!\n");
		cvm_help();
		#endif
		goto done;
	}

	switch(mode){
		case IPV4 :
				if(argc<3){
					fprintf(stderr,"IPV4 : Insufficient arguments !!");
					cvm_help();
					goto done;
				}
				retval = test_ipv4(argv[argc-1]);
			break;
		case SUBNET :
				if(argc<4){
					fprintf(stderr,"SUBNET : Insufficient arguments !!");
					cvm_help();
					goto done;
				}
				retval = test_subnet(argv[argc-2], argv[argc-1]);
			break;
		case RANGE :
				if(argc<4){
					fprintf(stderr,"SUBNET : Insufficient arguments !!");
					cvm_help();
					goto done;
				}
				retval = test_range(argv[argc-2], argv[argc-1]);
			break;
	}

done : 
	return retval;
}


int main(int argc, char* argv[])
{
	int c;
	int retval;
	int option_index;

	static struct option long_options[]={
		{"range", no_argument, &mode, RANGE},
		{"ipv4", no_argument, &mode, IPV4},
		{"subnet", no_argument, &mode, SUBNET},
		{"nomulticast", no_argument, &mcast, NO_MULTICAST},
		{"noreserved", no_argument, &resv, NO_RESERVED},
		{0, 0, 0, 0}
	};

	while(1){
		option_index = 0;
		c = getopt_long(argc, argv, "", long_options, &option_index);
		if(c==-1)
			break;
	}

	#ifdef DEBUG
	fprintf(stdout, "mode = %d, resv = %d, mcast = %d\n", mode, resv,
															mcast);
	#endif
	if(argc>2)
		ipval(argc, argv);
	else
	{
		fprintf(stderr, "Insufficient arguments !!\n");
		cvm_help();
		return -1;
	}
}
