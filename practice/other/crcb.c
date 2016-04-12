#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int crc32(unsigned char *message) {
	int i, j;
	unsigned int byte, crc, mask;

	i = 0;
	crc = 0xFFFFFFFF;
	while (message[i] != 0) {
		byte = message[i];            // Get next byte.
		crc = crc ^ byte;
		for (j = 7; j >= 0; j--) {    // Do eight times.
			mask = -(crc & 1);
			crc = (crc >> 1) ^ (0xEDB88320 & mask);
		}
		i = i + 1;
	}
	return ~crc;
}

int main(int argc, char* argv[])
{
	char* num = argv[1];
	unsigned int crcval = crc32((unsigned char*)num);
	if((argc-2)>0)
		fprintf(stdout, "out = %u\n", crcval%(argc-2));
}
