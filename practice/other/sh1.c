#include <stdio.h>

int main(int argc, char* arg[]){
	char a = 15;
	unsigned int b = 0;
	b |= 169<<24;
	b |= 254<<16;
	b |= 0x0000;
	printf("b = %x, %lu\n", b, b);
}
