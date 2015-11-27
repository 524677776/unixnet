#include "unp.h"

int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	if (argc != 2)
	{
		err_quit("usage: tcpcli <IPaddress>");
	}

	sockfd = Socket(AF_INT, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INT;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INT, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr) );

	str_cli(stdin, sockfd);

	return 0;
}