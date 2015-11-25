
#include "unp.h"

int main(int argc, char const *argv[])
{
	
	union {
		short s;
		char  c[sizeof(short)];
	}un;

	un.s = 0x0102;

	printf("%d\n", un.s);

	if(sizeof(short) == 2){
		if(un.c[0] == 1 && un.c[1] == 2)
			printf("%s\n", "big-endian");
		else if(un.c[0] == 2 && un.c[1] == 1)
			printf("%s\n", "little-endian");
		else
			printf("%s\n", "unknown");
	}else{
		printf("sizeof(short) = %zu\n", sizeof(short));
	}

	return 0;
}