#include <stdio.h>
#include <string.h>

struct non{
	int a;
	int b;
	int c;
	int d;
};

struct non na[8000000];

int main(int argc, char* argv[]){
	int i;
	//for(i=0;i<8000000;++i)
	//	memcpy(&na[i].a, &i, sizeof(int));
	for(i=0;i<8000000;++i)
		na[i].a = i;
	return 0;
}
