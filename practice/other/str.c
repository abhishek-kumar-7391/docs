#include <stdio.h>

int main(void){
	char* list[]={
		[1] = "hello",
		[255] = "world"
	};

	char line[256];
	memset(line, '\0', 256);
	sprintf(line, "%*s", 5, "hello");
	printf("%s\n", line);
	printf("len = %d\n", (int)strlen(line));
	printf("len = %d\n", (int)(strchr(line, '\0') - line));
}
