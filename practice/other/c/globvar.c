#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

const char* path="/tmp/clish_globvar";
enum STATUS{FILE_EXISTS=1, FILE_DOES_NOT_EXIST};


int update_globvar(const char* path, int file_status)
{
	int retval;
	int fd;
	int globvar;

	retval = 0;
	fd = -1;

	switch(file_status)
	{
		case FILE_EXISTS
			fd = open(path, O_RDWR);
			if(fd<0)
			{
				#ifdef DEBUG
				perror("open");
				#endif
				return -1;
			}

			
			
			break;
		
		case FILE_DOES_NOT_EXIST
			break;
	}

	return retval;
}


int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		#ifdef DEBUG
		fprintf(stderr, "Failure updating clish_globvar\n");
		#endif
		return -1;
	}
	if(!access(path, F_OK))
		return update_globvar(path, FILE_EXISTS);	
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "%s file does not exist !\n", path);
		#endif
		return update_globvar(path, FILE_DOES_NOT_EXIST);
	}
	return 0;
}
