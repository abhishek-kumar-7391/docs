#include <stdio.h>
#include <string.h>
#include <jansson.h>

int main(void){
	json_t* rep;

	rep = json_object();
	json_object_set_new(rep, "hello", json_string("worl"));
	printf("rep = %s\n", json_dumps(rep, JSON_COMPACT));
	return 0;
}
