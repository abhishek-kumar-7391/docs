#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

int main()
{
	int val;
	jmp_buf env_buffer;

	/* save calling environment for longjmp */
	printf("%s\n", __func__);
	val = setjmp( env_buffer );
	printf("hello\n");
	if( val != 0 ) 
	{
		printf("Returned from a longjmp() with value = %s\n", val);
		exit(0);
	}
	printf("Jump function call\n");
	jmpfunction( env_buffer );

	return(0);
}

void jmpfunction(jmp_buf env_buf)
{
	printf("%s\n", __func__);
	longjmp(env_buf, "abc");
}
