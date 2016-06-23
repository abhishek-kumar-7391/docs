#ifdef MODULE_UNIT_TESTING
#include <stdio.h>
#include <stdlib.h>
#endif
#include <string.h>

/* List of the white spaces, periods that need to be trimmed */
static char white_spaces_n_periods[]={' ', '.', ',', '\n', '\0'};

/* Check if the given charecter is a white space or a period*/
static int is_white_space_or_period(int c)
{
	int i;
	for(i=0; white_spaces_n_periods[i]!='\0'; i++) {
		if(c==white_spaces_n_periods[i])
			return 1;
	}
	return 0;	
}

/* Returned a new allcated string, that does not contain
 * any of the above mentioned white spaces or periods. */
char* trim_line(const char *line)
{
	const char *temp = line;
	const char *beg, *end;

	beg = temp;
	if(!(end = strchr(temp, '\0')))
		end = strchr(temp, '\n');
	end--;
	/* Move the beg and end pointers so that they point 
	 * to a string that no longer has white space or periods
	 * in the start or the end */
	while(*beg!='\0' && is_white_space_or_period(*beg)) 
		beg++;
	while(*end!='\0' && is_white_space_or_period(*end)) 
		end--;
	return strndup(beg, (end - beg) + 1);
}

#ifdef MODULE_UNIT_TESTING
int main(void)
{
	fprintf(stderr, " tl = %s\n", trim_line("hello world\n"));
	fprintf(stderr, " tl = %s\n", trim_line(" hello world"));
	fprintf(stderr, " tl = %s\n", trim_line(" hello world "));
	fprintf(stderr, " tl = %s\n", trim_line(" hello world. ,"));
}
#endif
