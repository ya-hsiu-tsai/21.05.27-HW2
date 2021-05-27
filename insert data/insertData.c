#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertData.h"

int insertData(int *insertData, char *argv)
{
	int i, len = 0;

	if(strcmp(argv, "1e4")==0)
	{
		len = 10000;
	}
	else if(strcmp(argv, "1e5")==0)
	{
		len = 100000;
	}
	else if(strcmp(argv, "1e6")==0)
	{
		len = 1000000;
	}
	for(i=0; i<len; i++)
	{
		insertData[i] = rand();
	}

	return len;
}