#include <stdio.h>
#include <stdlib.h>
struct some{
	int a,b,c,d;
};

#define PRINT_STRUCT(e1, e2, e3, e4) {\
	fprintf(stdout, "e1 = %d, e2 = %d, e3 = %d, e4 = %d\n", s->e1, s->e2, s->e3, s->e4);\
}

int main(void){
	struct some *s = malloc(sizeof(struct some));
	s->a = 10;
	s->b = 101;
	s->c = 1011;
	s->d = 10111;
	PRINT_STRUCT(a,b,c,d);
}
