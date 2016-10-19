#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char[] readFile(filePath) //filepath should be argv[1]
{

	File *file = fopen(filePath, "r");
	char input[] = "";
	
	
	if (file == 0 )
	{
		
		printf(" File failed to open \n");
		
	}
	
	char in;
	
	while ((in = fgetc(file)) != -1)
	{
		
		// reads each character in the file one by one
		input += in;
		
	}
	fclose(file);
	
	return input;

}