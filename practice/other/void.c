#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(void){
	void* src;
	uint8_t* dst;

	inet_pton(AF_INET, src, dst);
}
