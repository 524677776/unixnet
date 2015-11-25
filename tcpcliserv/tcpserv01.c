#include "unp.h"

int main(int argc, char const *argv[])
{
	int listenfd, connfd;
	pid_t childpid;
	socklen_t chilen;
	struct sockaddr_in cliaddr, servaddr;
	
	//create socket
	//listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	//bzero(&servaddr, sizeof(servaddr));


	// bind

	// listen

	// accept

	//  
	printf("%s\n", "hello!");
	return 0;
}