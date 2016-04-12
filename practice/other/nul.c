#include <stdio.h>
int main(void){
	char a[10];
	memset(a, '\0', 10);
	if(!a[0])
		printf("a = hello\n");
}
