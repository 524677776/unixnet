#ifndef __UNP_H__
#define __UNP_H__

#include <netinet/in.h> // for sockaddr_in{} 
#include <sys/socket.h> // socket() connect() bind() listen()
						// read() write() etc.

#include <strings.h>   // for bzero
#include <string.h>    // for strlen()
#include <stdlib.h>    // for exit
#include <errno.h>     // for errno
#include <stdio.h>     // for snprintf()


#define MAXLINE 100



#endif