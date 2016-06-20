#include <stdio.h>
int main(void)
{
//	unsigned long double a;
//	fprintf(stdout, "size = %lu\n", sizeof(a));
	char *a;
	a = malloc(10);
	fprintf(stdout, "size = %lu\n", sizeof(*a));
}
