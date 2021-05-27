#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "array.h"

int arrinsert(int *array, int key, int len)
{
	array[len] = key;
	len++;

	return len;
}

int arrfind(int *array, int key, int len)
{
	int i;

	for(i=0; i<len; i++)
	{
		if(array[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void array(int *insertData, int *searchData, int ilen, int slen)
{
	struct timeval start;
	struct timeval end;
	unsigned long idiff, sdiff;
	int array[ilen];
	int i, x, len = 0;

	gettimeofday(&start, NULL);
	for(i=0; i<ilen; i++)
	{
		len = arrinsert(array, insertData[i], len);
	}
	gettimeofday(&end, NULL);
	idiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("arr:\n");
	printf("bulding time: %f sec\n", idiff / 1000000.0);

	gettimeofday(&start, NULL);
	for(i=0; i<slen; i++)
	{
		x = arrfind(array, searchData[i], len);
	}
	gettimeofday(&end, NULL);
	sdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("query time: %f sec\n", sdiff / 1000000.0);
}