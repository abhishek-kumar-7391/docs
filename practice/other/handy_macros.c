#include <stdio.h>
#include <stdlib.h>
#define print(type) fprintf(stdout, "%d\n", n->type)

struct num{

int abc;

};


int main(void){
	struct num* n;
	n = malloc(sizeof(struct num));
	n->abc = 19;
	print(abc);
	return 0;
}

