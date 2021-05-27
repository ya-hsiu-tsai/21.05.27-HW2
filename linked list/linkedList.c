#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "linkedList.h"

struct node
{
	int num;
	struct node *next;
};

struct node *llinsert(struct node *head, int key)
{
	struct node *p;

	p = (struct node *)malloc(sizeof(struct node));
	p->num = key;
	p->next = head;

	return p;
}

struct node *llfind(struct node *head, int key)
{
	struct node *p = head;

	while(p)
	{
		if(p->num == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void linkedList(int *insertData, int *searchData, int ilen, int slen)
{
	struct timeval start;
	struct timeval end;
	unsigned long idiff, sdiff;
	struct node *head, *p;
	int i;

	head = NULL;
	gettimeofday(&start, NULL);
	for(i=0; i<ilen; i++)
	{
		head = llinsert(head, insertData[i]);
	}
	gettimeofday(&end, NULL);
	idiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("ll:\n");
	printf("bulding time: %f sec\n", idiff / 1000000.0);

	gettimeofday(&start, NULL);
	for(i=0; i<slen; i++)
	{
		p = llfind(head, searchData[i]);
	}
	gettimeofday(&end, NULL);
	sdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("query time: %f sec\n", sdiff / 1000000.0);
}