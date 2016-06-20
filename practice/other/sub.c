#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int  main(int argc, char* argv[]){
char* ip = argv[1];
char* mask = argv[2];

struct in_addr temp;

uint32_t start;
uint32_t end;


inet_aton(ip, &temp);
start = ntohl(temp.s_addr);

inet_aton(mask, &temp);
end = ntohl(temp.s_addr);

end = start | (~end);

fprintf(stdout, "start = %u\n", start);
fprintf(stdout, "end = %u\n", end);

fprintf(stdout, "host number = %d\n", end - start);


return 0;
}

