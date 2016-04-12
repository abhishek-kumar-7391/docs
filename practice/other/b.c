#include <stdio.h>
int main(){
	int a = 1;
	char b[2];
	fprintf(stderr, "a = %d\n", 1<<8);
	sprintf(b, "%d", 00000);
	fprintf(stderr, "b = %s\n", b);
}
