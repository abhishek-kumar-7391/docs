#include <stdio.h>

//#define BLACK  "\033[22;30m"
//#define GREEN  "\033[22;31m"

#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"
#define MAKE_BLUE "\e[0;34m"


int main(){
	printf("\033[H\033[2J");
	sleep(5);
	fflush(stdout);
	printf("\033[H");
	//printf(MAKE_BLUE "this will show up blue" RESET_COLOR "\n");
}
