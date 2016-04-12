#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void dump_array(uint8_t* arr){
	int i;
	for(i=0;arr[i]!='\0';++i){
		fprintf(stdout, "arr[%d] = %d,", i, arr[i]);
	}
	fprintf(stdout, "\n");
}

int main(int argc, char* argv[]){
	uint8_t arr[] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, NULL};
	dump_array(arr);
	arr[1] = 255 >> (8 - 5);
	dump_array(arr);
	return 0;
}
