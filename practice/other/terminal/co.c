
//#define BLACK  "\033[22;30m"
//#define GREEN  "\033[22;31m"

#define RESET_COLOR "\e[m"
#define MAKE_GREEN "\e[32m"
#define MAKE_BLUE "\e[0;34m"


int main(){
	printf(MAKE_BLUE "this will show up blue" RESET_COLOR "\n");
}
