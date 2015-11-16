#ifndef __ERROR_H__
#define __ERROR_H__

#include    "unp.h"
#include    <stdarg.h>          /* ANSI C header file */
#include    <syslog.h>          /* for syslog() */

int     daemon_proc;            /* set nonzero by daemon_init() */

static void err_doit(int, int, const char *, va_list);

void err_quit(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_ret(const char *fmt, ...);

#endif // __ERROR_H__