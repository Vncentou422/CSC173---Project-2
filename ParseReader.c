#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{

	File *file = fopen(argv[1], "r");
	
	if (file == 0 )
	{
		
		printf(" File failed to open \n");
		
	}
	
	char in;
	
	while ((in = fgetc(file)) != -1)
	{
		
		// reads each character in the file one by one
		
	}
	fclose(file);

}