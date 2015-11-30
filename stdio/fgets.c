#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	FILE *pFile;
	char mystr[100];

	pFile = fopen("myfile.txt", "r");
	if(pFile == NULL)
		perror("open file error");
	else if( fgets(mystr, 100, pFile) != NULL)
		puts(mystr);
	else
		fclose(pFile);

	return 0;
}