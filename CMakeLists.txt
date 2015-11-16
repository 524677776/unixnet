project(unixnet)
cmake_minimum_required(VERSION 2.8)

include_directories(lib)
include_directories(daytimetcp)

add_library(liberror SHARED "lib/error.h" "lib/error.c")
add_library(libwrapsock SHARED "lib/wrapsock.h" "lib/wrapsock.c")
add_library(libwrapunix SHARED "lib/wrapunix.h" "lib/wrapunix.c")
target_link_libraries(libwrapsock liberror)
target_link_libraries(libwrapunix liberror)

add_executable(daytimetcpcli "daytimetcp/daytimetcpcli.c")
target_link_libraries(daytimetcpcli liberror)

add_executable(daytimetcpsrv "daytimetcp/daytimetcpsrv.c")
target_link_libraries(daytimetcpsrv liberror libwrapsock libwrapunix)