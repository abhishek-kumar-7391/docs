#include <stdio.h>
#include <string.h>
int main(void){
	const char* str = "hello+wotrld=\0";
	char* ptr = index(str, '+') + 1;
	printf("ptr = %s\n", ptr);
}
