#include <stdio.h>

static void 
print_array_int(int *arr, int size, char delim)
{
	int i;
	for(i = 0; )	
}

struct array {
	int size;
};

static void 
print_array(void *arr, int size, int start_at, int end_at, char delim, uint8_t type)
{
	int *arr_int;
	char *arr_char;

	switch(type) {
		case INT:
			arr_int = arr;
			print_array_int(arr_int, size, start_at, end_at, delim);
			break;
		case CHAR:
			arr_char = arr;
			break;
		default:
			fprintf(stderr, "Array type not recognized\n");
			return;
	}
		
	return;
}

int 
main(void)
{
	int arr[10];
	memset(arr, 1, sizeof arr);
	print_array();	
}
