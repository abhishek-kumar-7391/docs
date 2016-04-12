#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
pid_t ppid;


static void daemonise_child(void){
	int in, new_in = 10;
	int out, new_out = 11;
	int err, new_err = 12;

	signal(SIGCHLD, SIG_IGN);
    	signal(SIGHUP, SIG_IGN);
	openlog(NULL, LOG_CONS|LOG_PID, LOG_USER);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	while(1){
		if(getppid()==ppid){
			syslog(LOG_INFO, "PARENT ALIVE :-), cpid = %d\n", getpid());	
			sleep(2);
		}
		else{
			syslog(LOG_INFO, "PARENT DIED :-(\n");
			exit(EXIT_SUCCESS);
		}
	}
}

int main(void){
	pid_t pid;
	ppid = getpid();
	if(!fork())
		daemonise_child();
	else{
		while(1){
			fprintf(stdout, "This is parent %d\n", ppid);
			sleep(1);
		}
	}
}
