#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*func)(int,int);
struct callback{
int opid;
func fn;
};



int call_1(int a, int b){
	return a+b;
}

int call_2(int a, int b){
	return a-b;
}

struct callback handler_table[]={
	{1, call_1},
	{2, call_2},
	{0, 0}
};

int main(int argc, char* argv[]){
	int a = 10;
	int b = 10;
	int i;
	struct callback cb;

	for(i=0;i<2;++i){
		cb.fn = handler_table[i].fn;
		fprintf(stdout, "opid = %d, ans = %d\n", handler_table[0].opid, cb.fn(a, b));
	}
return 0;
}
