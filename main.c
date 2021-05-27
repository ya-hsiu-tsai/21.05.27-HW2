#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "BSarray.h"
#include "linkedList.h"
#include "BStree.h"
#include "insertData.h"
#include "searchData.h"
int insert[1000000];
int search[1000000];

int main(int argc, char *argv[])
{
	int i, ilen, slen;

	for(i=0; i<argc; i++)
	{
		if(strcmp(argv[i], "-d") == 0)
		{
			ilen = insertData(insert, argv[i+1]);
		}
		else if(strcmp(argv[i], "-q") == 0)
		{
			slen = searchData(search, argv[i+1]);
		}
		else if(strcmp(argv[i], "-bst") == 0)
		{
			BStree(insert, search, ilen, slen);
			printf("\n");
		}
		else if(strcmp(argv[i], "-bs") == 0)
		{
			BSarray(insert, search, ilen, slen);
			printf("\n");
		}
		else if(strcmp(argv[i], "-arr") == 0)
		{
			array(insert, search, ilen, slen);
			printf("\n");
		}
		else if(strcmp(argv[i], "-ll") == 0)
		{
			linkedList(insert, search, ilen, slen);
			printf("\n");
		}
	}

	return 0;
}