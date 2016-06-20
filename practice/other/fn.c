#include <stdio.h>
typedef int (*func)(int, int);
int add(int, int);
int main(){
	
	int a = 10;
	int b = 20;
	int (*func)(int,int)=add;
	int c = func(a, b);
	printf("%d", c);
	return 0;
}

int add(int a, int b){
	return a+b;
}


