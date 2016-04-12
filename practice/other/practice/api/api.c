#include <stdio.h>
#include "api.h"
void hello(void)
{
	fprintf(stdout, "on = %d\n", on);
	fprintf(stdout, "off = %d\n", off);
}

