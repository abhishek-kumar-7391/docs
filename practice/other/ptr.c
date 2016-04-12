#include <stdio.h>
int main(){
	char* a;
	if(a!=NULL)
		printf("not null\n");
	else
		printf("null\n");
	printf("a = %c\n", a[0]);
	return 0;
}
