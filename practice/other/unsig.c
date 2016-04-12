#include <stdio.h>
unsigned char a;
int main()
{
	return fprintf(stdout, "a = %u\n", a);
}
