#include <stdio.h>

typedef void(*sum)(int, int);

inline void add(int a, int b){
	printf("a = %d, b = %d, sum = %d\n", a, b, a+b);
}

int main(int argc, char* argv[]){
	int a = argv[1]? atoi(argv[1]):10;
	printf("a = %d\n", a);
	
	int b = argv[2]? atoi(argv[2]):20;
	printf("b = %d\n", b);

	sum fn;	
	fn = add;
	fn(a,b);
	return 0;
}
