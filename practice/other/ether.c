#include <stdio.h>
#include <string.h>

struct a{
	uint8_t addr_bytes[ETHER_ADDR_LEN];
};

struct the{
	struct a d_addr;
	struct a s_addr;
};

int main(){
	struct the t;
}
