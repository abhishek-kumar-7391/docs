#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

int bits_set(int num){
	int count = 0;
	for(; num;++count)
		num = num & (num-1);
	return count;
}

int main(void)
{
	printf("%d\n", bits_set(15));
	#if 0
	uint8_t a=128;
	uint8_t max = UCHAR_MAX;
	int count;
	count = 0;

	while(a & UCHAR_MAX)
	{
		++count;
		a = a >>1;
	}
	fprintf(stdout, "count = %d\n", count);
	return count;
	#endif

}
