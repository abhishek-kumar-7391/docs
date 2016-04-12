#include <stdio.h>

int main(){
	unsigned int tcp;
	unsigned int udp;
	unsigned int group;
	unsigned int i;
	tcp = 1;
	udp = 3;
	group = 0;
	group |= 1<<tcp;
	group |= 1<<udp;
//	fprintf(stdout, "group = %d\n", group);
#if 0
	for(i=0;i<8000000;++i){
		if((i==tcp) || (i == udp))
			printf("tcp or udp\n");
		else if(i==10){
			printf("oops\n");
		}
	}
#endif
	int j = 0;
	for(i=0;i<8000000;++i){
		if((1<<j) & group)
			printf("found, %d, %d\n", (1<<j) & group, i);
		else if(i==10)
			printf("not found");
		j++;
		if(j>30)
			j = 0;
	}
	//printf("i = %d\n", i);
}
