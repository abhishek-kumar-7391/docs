#include <stdio.h>

void change();
void no_change();

int back_slash;
char ch;

int 
main(void){
	fprintf(stdout, "Input : ");
	for(;;){
		ch = getchar();
		if(ch=='\n')
			break;
		else if(ch=='\\') /* no change */
			no_change();
		else
			change();
	}
return 0;	
}

void no_change(){
	ch = getchar();
	fprintf(stdout, "%c", ch);
}

void change(){
	if(ch>=97 && ch<=122)
		ch-=32;
	else if(ch>=48 && ch <=57)
		ch='*';
	fprintf(stdout, "%c", ch);
}


