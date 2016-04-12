#include <stdio.h>
#include <string.h>
struct play{
	int c;
	int d;
	int e;
};


int main(int argc, char* argv[]){
	struct play p;
	struct play a = {0};
	unsigned long int i;
	for(i=0;i<80000000;++i){
		p.c = 10;
		p.d =123;
		p.e =123;
		p = a;
	//memset(&p, '\0', sizeof(p));
		//fprintf(stdout, "c = %d\n", p.c);
	//	fprintf(stdout, "b = %d\n", p.d);
	//	fprintf(stdout, "a = %d\n", p.e);
		//sleep(1);
	}
	return 0;
}
