#include <stdio.h>
struct num{
	int a;
};

int main()
{
	struct num n[10] = {10};
	int i;
	for(i = 0;i<10;++i)
		printf("a = %d\n", n[i].a);
}
