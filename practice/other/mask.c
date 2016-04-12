#include <stdio.h>

int main(int argc ,char* argv[]){
int mask_int = atoi(argv[1]);
int i;
char* ptr;
unsigned char byte;

	byte = 255;

char* mask = malloc(15);
ptr = mask;

	for(i=1;i<=4;++i){
		
		if((mask_int < 8) && (mask_int>0)){
			byte = byte<<(8 - mask_int);
			mask_int = 0;
		}else if(!mask_int){
			byte = 0;
		}else mask_int-=8;
		
		switch(i){
			case 1 : 
			case 2 : 
			case 3 : 
				sprintf(mask, "%d.", byte);
				break;
			case 4 : 
				sprintf(mask, "%d", byte);
				break;
		}
		if(byte>=100)
			mask = mask+4;
		else if(byte>=10)
			mask+=3;
		else
			mask+=2;

		byte = 255;
	}
	mask = ptr;
	fprintf(stderr, "mask = %s\n", mask);
return 0;
}
