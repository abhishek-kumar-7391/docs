#include <stdio.h>
#include <unistd.h>

int main(void)
{
	long cpu_count = 0;
	cpu_count = sysconf(_SC_NPROCESSORS_ONLN);
	printf("cpu_count = %ld\n", cpu_count);
	return 0;
}
