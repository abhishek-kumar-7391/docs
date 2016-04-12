#include <stdio.h>
int main(void){
	char cmd[1024];
	const char* path = "/home/test/practice/other/random";
	sprintf(cmd, "rm -rf %s", path);
	printf("%d\n", system(cmd));
	perror("system");
	return 0;
}
