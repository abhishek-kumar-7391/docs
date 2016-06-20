#include <stdio.h>
#include <stdint.h>
struct some{
	uint64_t a,b,c,d;
};
int main(void){
	fprintf(stderr, "a = %ld\n", (long)offsetof(struct some, a));
}
