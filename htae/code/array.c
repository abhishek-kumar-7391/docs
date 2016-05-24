#include <stdio.h>
#include <string.h>

int 
main(int argc, char* argv[])
{
	int a;
	char buf[10];

	a = 10;
	printf("a = %d\n", a);
	strcpy(buf, argv[1]);
	printf("a = %d\n", a);
	return 0;
}
