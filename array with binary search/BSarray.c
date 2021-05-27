#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "BSarray.h"

int BSainsert(int *array, int key, int len)
{
	array[len] = key;
	len++;

	return len;
}

void sort(int *array, int left, int right)
{
	int i = left-1;
	int j;
	int temp;
	int p;

	if(left < right)
	{
		for(j=left; j<right; j++)
		{
			if(array[j] <= array[right])
			{
				i++;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		i++;
		temp = array[i];
		array[i] = array[right];
		array[right] = temp;
		p = i;
		sort(array, left, p-1);
		sort(array, p+1, right);
	}
}

int BSafind(int *array, int key, int len)
{
	int mid, low = 0, high = len-1;

	while(low <= high)
	{
		mid = (low + high)/2;
		if(array[mid] == key)
		{
			return mid;
		}
		else if(array[mid] > key)
		{
			high = mid - 1;
		}
		else if(array[mid] < key)
		{
			low = mid + 1;
		}
	}
	return -1;
}

void BSarray(int *insertData, int *searchData, int ilen, int slen)
{
	struct timeval start;
	struct timeval end;
	unsigned long idiff, sdiff;
	int array[ilen];
	int i, x, len = 0;

	gettimeofday(&start, NULL);
	for(i=0; i<ilen; i++)
	{
		len = BSainsert(array, insertData[i], len);
	}
	sort(array, 0, len-1);
	gettimeofday(&end, NULL);
	idiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bs:\n");
	printf("bulding time: %f sec\n", idiff / 1000000.0);

	gettimeofday(&start, NULL);
	for(i=0; i<slen; i++)
	{
		x = BSafind(array, searchData[i], len);
	}
	gettimeofday(&end, NULL);
	sdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("query time: %f sec\n", sdiff / 1000000.0);
}