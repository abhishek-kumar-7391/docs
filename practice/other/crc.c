#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ---------------------------- reverse --------------------------------

// Reverses (reflects) bits in a 32-bit word.
unsigned reverse(unsigned x) {
	x = ((x & 0x55555555) <<  1) | ((x >>  1) & 0x55555555);
	x = ((x & 0x33333333) <<  2) | ((x >>  2) & 0x33333333);
	x = ((x & 0x0F0F0F0F) <<  4) | ((x >>  4) & 0x0F0F0F0F);
	x = (x << 24) | ((x & 0xFF00) << 8) |
		((x >> 8) & 0xFF00) | (x >> 24);
	return x;
}

// ----------------------------- crc32a --------------------------------

/* This is the basic CRC algorithm with no optimizations. It follows the
   logic circuit as closely as possible. */

unsigned int crc32a(unsigned char *message) {
	int i, j;
	unsigned int byte, crc;

	i = 0;
	crc = 0xFFFFFFFF;
	while (message[i] != 0) {
		byte = message[i];            // Get next byte.
		byte = reverse(byte);         // 32-bit reversal.
		for (j = 0; j <= 7; j++) {    // Do eight times.
			if ((int)(crc ^ byte) < 0)
				crc = (crc << 1) ^ 0x04C11DB7;
			else crc = crc << 1;
			byte = byte << 1;          // Ready next msg bit.
		}
		i = i + 1;
	}
	return reverse(~crc);
}

unsigned int crc32b(unsigned char *message) {
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
unsigned int crc32c(unsigned char *message) {
	int i, j;
	unsigned int byte, crc, mask;
	static unsigned int table[256];

	/* Set up the table, if necessary. */

	if (table[1] == 0) {
		for (byte = 0; byte <= 255; byte++) {
			crc = byte;
			for (j = 7; j >= 0; j--) {    // Do eight times.
				mask = -(crc & 1);
				crc = (crc >> 1) ^ (0xEDB88320 & mask);
			}
			table[byte] = crc;
		}
	}

	/* Through with table setup, now calculate the CRC. */

	i = 0;
	crc = 0xFFFFFFFF;
	while ((byte = message[i]) != 0) {
		crc = (crc >> 8) ^ table[(crc ^ byte) & 0xFF];
		i = i + 1;
	}
	return ~crc;
}
int main(int argc, char* argv[])
{
	char* num = argv[1];
	unsigned int crcval = crc32a((unsigned char*)num);
	fprintf(stdout, "crcval = %u\n", crcval);
	if((argc-2)>0)
		fprintf(stdout, "out = %u\n", crcval%(argc-2));
}
