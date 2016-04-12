#include <stdio.h>
int main()
{
	unsigned char arr[] = {1,2};
	short num;

	num = *(short*)arr;
	fprintf(stdout, "num = %d\n", num);

	return 0;
}
