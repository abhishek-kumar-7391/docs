#include <stdio.h>
int main(){
char* ptr[] = {"abc", "def", "ghi"};
fprintf(stdout, "ptr = %s\n", *ptr);
return 0;
}
