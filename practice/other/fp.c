#include <stdio.h>
int main(int argc, char* argv[]){
	int a = (argc>1)?atoi(argv[1]):10;
	int b = (argc>2)?atoi(argv[2]):20;
	if(!argv[1])
		printf("arg1 is null\n");
	if(!argv[2])
		printf("arg2 is null\n");
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
