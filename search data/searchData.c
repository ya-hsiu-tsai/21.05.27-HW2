#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "searchData.h"

int searchData(int *searchData, char *argv)
{
	int i, len = 0;

	if(strcmp(argv, "1e3")==0)
	{
		len = 1000;
	}
	else if(strcmp(argv, "1e4")==0)
	{
		len = 10000;
	}
	else if(strcmp(argv, "1e5")==0)
	{
		len = 100000;
	}
	srand(time(NULL));
	for(i=0; i<len; i++)
	{
		searchData[i] = rand();
	}

	return len;
}