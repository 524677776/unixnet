/* 
* @Author: gw
* @Date:   2015-11-21 23:16:19
* @Last Modified by:   gw
* @Last Modified time: 2015-11-29 19:29:03
*/

#include <sys/types.h> // pid_t ...
#include <netinet/in.h>  // for sockaddr_in
#include <stdio.h> 
#include <errno.h>
#include <stdlib.h>  // for exit
#include <strings.h> //for bzero

#define SERV_PORT 9877
#define SOMAXCONN 128
#define MAXLINE 100

void err(char *e)
{
	perror(e);
	exit(1);
}

ssize_t writen(int fd, const void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr = vptr;
	nleft = n;
	while(nleft > 0) {
	    if((nwritten = write(fd, ptr, nleft)) <= 0){
	    	if(errno == EINTR)
	    		nwritten = 0;
	    	else
	    		return -1;
	    }

	    nleft -= nwritten;
	    ptr += nwritten;
	}

	return n;
}

void Writen(int fd, void *ptr, size_t nbytes)
{
	if(writen(fd, ptr, nbytes) != nbytes)
		err("writen error");
}

void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];

	again:
	while((n = read(sockfd, buf, MAXLINE)) > 0)
		Writen(sockfd, buf, n);

	if(n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err("str echo error");
}

int main(int argc, char const *argv[])
{
	int listenfd, connfd;
	pid_t childpid;

	perror("abc");

	printf("%s\n", "hello!");

	socklen_t chilen;
	struct sockaddr_in cliaddr, servaddr;
	
	if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
		err("socket error");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		err("bind error");

	if(listen(listenfd, SOMAXCONN) < 0)
		err("listen error");

	for(;;){
		if((connfd = accept(listenfd, NULL, NULL)) == -1)
			err("accept error");

		if((childpid == fork()) == -1)
			err("fork error");

		if(childpid == 0){
			close(childpid);
			str_echo(connfd);
			exit(0);
		}

		close(connfd);

	}


/*


	//create socket
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	// bind
	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

	// listen
	Listen(listenfd, LISTENQ);

	// accept
	for ( ; ; ){
		chilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *) &cliaddr, &chilen);

		if ((childpid = Fork()) == 0){
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}*/

	return 0;
}