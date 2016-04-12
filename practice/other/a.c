#include <stdio.h>
#include <jansson.h>
#include <zmq.h>
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define MAJOR_VER 2
#define MINOR_VER 6
#define MY_FILE "/home/user/.myapp" STR(MAJOR_VER) STR(MINOR_VER)

int main()
{

	fprintf(stdout, "%s\n", MY_FILE);
	char* ptr = "entry->stats."STR(ibytes)"."STR(low);
	fprintf(stdout, "%s\n", ptr);
}
