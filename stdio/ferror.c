#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *pFile;
	pFile = fopen("myfile.txt", "r");
	if(pFile == NULL)
		perror("fopen error");
	else{
		fputc('x', pFile);
		if(ferror(pFile))
			perror("fputs error");
		fclose(pFile);
	}


	return 0;
}