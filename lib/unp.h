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


#define MAXLINE 100

#define SA struct sockaddr

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

#endif