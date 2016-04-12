#include <stdio.h>
#define fin 1
/*
#define flag_present(mask, flag) (((flag##_mask)&mask)==flag##_mask)
#define join(str1) str1##_mask
#define print(fp,some) \
	{ \
		char flag[12]; \
		sprintf(flag,  "%s", some);\
		fprintif(stdout, "fin = %d\n", #flag_mask);	\
	}
char mask = 1;
*/
//#define flag_pre(mask,flag) mask&(1<<#flag)
int flag_fin(int mask)
{
	fprintf(stdout, "mask = %d\n", mask);
	return 0;
}
int main()
{
/*
	fprintf(stdout, "fin = %d\n", flag_present(mask, fin));
	FILE* fp = stdout;
	char* str = "fin";
	print(fp, str);
*/
	char* flag="fin";
	//int a = flag_pre(1, flag);
	//fprintf(stdout, "a = %d\n", a);
	flag_pre(1, flag);
}
