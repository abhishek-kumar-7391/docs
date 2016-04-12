#include "update.h"
#include "parse_cmdline.h"
const char* tgt = "./dummy.txt"; // file to be updated

int read_file(const char* path, const char* start, const char* fend){
	FILE* fp;
	ssize_t read_ret;
	size_t read_size;
	char* line;
	const char* str = start;
	const char* end = fend;
	int on = 0;
	size_t stlen = strlen(str);
	size_t linelen;
	char space = ' ';

	line = NULL;
	read_ret = 0;
	read_size = 0;
	fp = fopen(path, "r+");
	fprintf(stdout, "start = %s, end = %s\n", start, fend);
	for(;;){
		read_ret = getline(&line, &read_size, fp);
		if(read_ret == -1)
			break;
		linelen = strlen(line) - (size_t)1;
		printf("linelen = %d, line = %s\n", linelen, line);
		if(linelen > 0 && !strncmp(line, str, linelen)){
			printf("------------ start = %s\n", line);
			on = 1;
			while(1){
				if((linelen > 0) && !strncmp(line, end, linelen)){
					fseek(fp, (0 - (linelen)) - 1, SEEK_CUR);
					fprintf(fp, "%*c", (int)linelen, space);
					printf("--------- end = %s\n", end);
					on = 0;
				}
			
				if(on){
					fseek(fp, (0 - (linelen)) - 1, SEEK_CUR);
					fprintf(fp, "%*c", (int)linelen, space);
				}

				read_ret = getline(&line, &read_size, fp);
				if(read_ret == -1)
					goto done;
				linelen = strlen(line) - (size_t)1;
			}
		}
	}
done:
	return 0;
}

int main(int argc, char* argv[]){
	static struct option longopt[]={
		{"tgt", required_argument, 0, 't'},
		{"src", required_argument, 0, 's'},
		{"begin", required_argument, 0, 'b'},
		{"end", required_argument, 0, 'e'},
		{0,0,0,0}
	};
	
	const char* shortopt = "t:s:b:e:";
	const char* begin;
	const char* end;

	begin = end = NULL;
	parse_cmdline(argc, argv, longopt, shortopt);
	begin = get_optarg_by_shortopt('b');
	if(!begin)
		exit(EXIT_FAILURE);
	end = get_optarg_by_shortopt('e');
	if(!end)
		exit(EXIT_FAILURE);
	read_file(tgt, begin, end);
	return 0;
}
