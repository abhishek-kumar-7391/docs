#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
int main(void){
	cpu_set_t count;
	printf("cpu = %d\n", CPU_COUNT(&count));
# ifdef _SC_NPROCESSORS_ONLN
	int nprocs = 0;
	    nprocs = sysconf( _SC_NPROCESSORS_ONLN );
	printf("nproces = %d\n", nprocs);
#endif
	return 0;
}
