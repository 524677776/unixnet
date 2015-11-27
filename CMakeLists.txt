project(unixnet)
cmake_minimum_required(VERSION 2.8)

include_directories(lib)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
CHECK_FUNCTION_EXISTS(epoll_wait HAVE_EPOLL_WAIT)

configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)

set(LIBSRC 
	"lib/error.c" 
	"lib/wrapsock.c" 
	"lib/wrapunix.c"
	"lib/str_cli.c"
	"lib/str_echo.c"
	)

add_executable(daytimetcpcli "daytimetcp/daytimetcpcli.c" ${LIBSRC})
add_executable(daytimetcpsrv "daytimetcp/daytimetcpsrv.c" ${LIBSRC})
add_executable(byteorder "byteorder/byteorder.c")
add_executable(tcpserv01 "tcpcliserv/tcpserv01.c" ${LIBSRC})
add_executable(tcpcli01 "tcpcliserv/tcpcli01.c" ${LIBSRC})