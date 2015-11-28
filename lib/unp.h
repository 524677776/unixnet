#ifndef __UNP_H__
#define __UNP_H__

#include <netinet/in.h> // for sockaddr_in{} 
#include <sys/socket.h> // socket() connect() bind() listen()
						// read() write() etc.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

#define MAXLINE  100

#define SA struct sockaddr

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */


/* for wrapsock */
int 	Socket(int family, int type, int protocol);
int 	Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void 	Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void 	Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void 	Listen(int fd, int backlog);
int 	Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
void 	Send(int fd, const void *ptr, size_t nbytes, int flags);

/* for error */
void err_quit(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_ret(const char *fmt, ...);

/* for wrapunix */
void 	Close(int fd);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void 	Write(int fd, void *ptr, size_t nbytes);


#endif