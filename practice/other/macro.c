#include <stdio.h>
#define merge(param) set_socket_##param();
#define print(abc, f) fprintf(stdout, "%s = "f"\n", #abc, abc);

#define ACCT_IPSET_SRC_RX 1
#define ACCT_IPSET_SRC_TX 2
#define ACCT_IPSET(type) {\
	fprintf(stdout, "%d\n", ACCT_IPSET_SRC_##type); \
}
void set_socket_abc()
{
	printf("%s\n", __func__);
}

int main()
{
	int a = 10;
	float f = 1.2;
	merge(abc);
	ACCT_IPSET(RX);
//	ACCT_IPSET(SRC, TX);
}
