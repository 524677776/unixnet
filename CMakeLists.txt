project(unixnet)
cmake_minimum_required(VERSION 2.8)

include_directories(lib)
include_directories(daytimetcp)
include_directories(byteorder)

add_executable(daytimetcpcli "daytimetcp/daytimetcpcli.c" "lib/error.c" "lib/wrapsock.c" "lib/wrapunix.c")

add_executable(daytimetcpsrv "daytimetcp/daytimetcpsrv.c" "lib/error.c" "lib/wrapsock.c" "lib/wrapunix.c")

add_executable(byteorder "byteorder/byteorder.c")