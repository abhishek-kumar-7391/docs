#include <stdio.h>
#include <unistd.h>

int main(){
	int pid;

	pid = fork();
	if(!pid){
		while(1){
			sleep(1);
			printf("%d\n",getppid());
		}
	}
	else{
			printf("parent %d\n",getppid());
	}
	return 0;
}

