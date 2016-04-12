#include <stdio.h>
#include <fcntl.h>
int main()
{
	int a = 0x653465;
	char b = (char)a;
	fprintf(stdout, "a = %x\n", a);
	fprintf(stdout, "b = %x\n", b);
	fprintf(stdout, "b = %c\n", b);

	int fd = open("./file", O_CREAT|O_WRONLY);
	perror("open");
	write(fd, &a, sizeof(a));
	write(fd, "\n", sizeof(char));
	write(fd, &a, sizeof(a));
	write(fd, "\n", sizeof(char));
	write(fd, &a, sizeof(a));
	write(fd, "\n", sizeof(char));
	close(fd);
}

