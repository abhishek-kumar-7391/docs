#include <stdio.h>

int main()
{
	char *str="hello";
	printf("%s\n", "str");
 	#if 0
	int b = 513;
	char* a;
	a = (char*)&b;	
	fprintf(stdout, "byte1 = %d\n", *a);
	++a;
	fprintf(stdout, "byte2 = %d\n", *a);
	
	void* val;
	val = &b;
	fprintf(stdout, "b = %u, *val = %u, val = %u\n", sizeof(b), sizeof(*val), sizeof(val));
	#endif
}
