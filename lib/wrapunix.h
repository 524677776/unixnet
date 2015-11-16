#ifndef __WRAPUNIX_H__
#define __WRAPUNIX_H__

#include "unp.h"
#include "error.h"

void 	Close(int fd);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void 	Write(int fd, void *ptr, size_t nbytes);

#endif // __WRAPUNIX_H__
