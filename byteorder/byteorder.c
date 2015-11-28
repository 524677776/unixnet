/* 
* @Author: gw
* @Date:   2015-11-17 01:00:26
* @Last Modified by:   gw
* @Last Modified time: 2015-11-21 23:13:24
*/

#include <unp.h>

int main(int argc, char** argv) {

	union{
		short s;
		char  c[sizeof(short)];
	}un;

	un.s = 0x0102;
	//printf("%s\n", CPU_VENDOR_OS);

    return 0;
}