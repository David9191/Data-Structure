#ifndef	_HEAP_H_
#define	_HEPA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef	struct HeapNodeType
{
	int			data;
}				HeapNode;

typedef struct HeapType
{
	int			maxCount;
	int			currentCount;
	HeapNode	*pData;
}				ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap	createHeapMax(int maxCount);
void			deleteHeapMax(ArrayMaxHeap heap);
int				insertHeapMax(ArrayMaxHeap heap, int data);
HeapNode 		removeHeapMax(ArrayMaxHeap heap); // remove heap's root node and return removed root node


ArrayMinHeap	createHeapMin(int maxCount);
void			deleteHeapMin(ArrayMinHeap heap);
int				insertHeapMin(ArrayMinHeap heap, int data);
HeapNode 		removeHeapMin(ArrayMinHeap heap); // remove heap's root node and return removed root node

#define	TRUE		1
#define	FALSE		0
#define	ERROR		-1

#endif