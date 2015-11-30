/* 
* @Author: gw
* @Date:   2015-11-29 21:03:58
* @Last Modified by:   gw
* @Last Modified time: 2015-11-29 22:14:39
*/

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <strings.h>

#define SERV_PORT 9877
#define MAXLINE 100

void err(char *msg)
{
	perror(msg);
	exit(1);
}

void str_cli(FILE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];

	while(Fgets(sendline, MAXLINE, fp) != NULL) {
	    Writen(sockfd, sendline, strlen(sendline));
	    if(Readline(sockfd, recvline, MAXLINE) == 0)
	    	err("str cli : server terminated prematurely");
	    Fputs(recvline, stdout);
	}
}

int main(int argc, char const *argv[])
{
	int sockfd, n;
	struct sockaddr_in servaddr;

	if(argc != 2)
		err("usage: tcpcli <ipaddress>");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		err("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT)

	n = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	if(n < 0 || n == 0)
		err("inet pton error");

	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		err("connect error");


	str_cli(stdin, sockfd);


	return 0;
}