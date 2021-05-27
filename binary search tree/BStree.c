#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "BStree.h"

struct node
{
	int num;
	struct node *left;
	struct node *right;
};

struct node *BStinsert(struct node *root, int key)
{
	if(root == NULL)
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->left = NULL;
		root->right = NULL;
		root->num = key;
		return root;
	}
	if(root->num > key)
	{
		root->left = BStinsert(root->left, key);
	}
	else
	{
		root->right = BStinsert(root->right, key);
	}
	return root;
}

int BStfind(struct node *root, int key)
{
	if(root == NULL)
	{
		return -1;
	}
	else if(root->num == key)
	{
		return root->num;
	}
	else if(root->num > key)
	{
		return BStfind(root->left, key);
	}
	else if(root->num < key)
	{
		return BStfind(root->right, key);
	}
}

void BStree(int *insertData, int *searchData, int ilen, int slen)
{
	struct timeval start;
	struct timeval end;
	unsigned long idiff, sdiff;
	struct node *root;
	int i, p;

	root = NULL;
	gettimeofday(&start, NULL);
	for(i=0; i<ilen; i++)
	{
		root = BStinsert(root, insertData[i]);
	}
	gettimeofday(&end, NULL);
	idiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bst:\n");
	printf("bulding time: %f sec\n", idiff / 1000000.0);

	gettimeofday(&start, NULL);
	for(i=0; i<slen; i++)
	{
		p = BStfind(root, searchData[i]);
	}
	gettimeofday(&end, NULL);
	sdiff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("query time: %f sec\n", sdiff / 1000000.0);
}