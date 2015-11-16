#ifndef __WRAPSOCK_H
#define __WRAPSOCK_H

#include "unp.h"
#include "error.h"

int 	Socket(int family, int type, int protocol);
int 	Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void 	Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void 	Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void 	Listen(int fd, int backlog);
int 	Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
void 	Send(int fd, const void *ptr, size_t nbytes, int flags);

#endif // __WRAPSOCK_H
