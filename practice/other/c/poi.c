#include <stdio.h>
struct some{
	int a;
	int b;
};

struct some* global;

void def(struct some* l){
	global = l;
}

int main(void){
	struct some s = {1,2};
	def(&s);
	printf("%d, %d\n", global->a, global->b);
	return 0;
}
