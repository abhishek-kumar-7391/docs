#include <stdio.h>

int main(void)
{
	int arr[10];
	int i;

	for(i=0;i<10;i++)
		arr[i] = i;
	for(i=0;i<10;i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	return 0;
}
