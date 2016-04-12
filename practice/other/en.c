#include <stdio.h>
#include <fcntl.h>
int main()
{
	int x;
	x = 258;
	
	fprintf(stdout, "x = %x\n", x);
	int fd = open("file", O_CREAT|O_WRONLY|O_RDONLY);
	perror("open");
	write(fd, &x, sizeof(x));
	return 0;
}

