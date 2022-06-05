#ifndef	_HEAP_H_
#define	_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef	struct HeapNodeType
{
	int			data;
	int			from;
	int			to;
}				HeapNode;

// MinHeap == "완전이진트리" && "최소트리"
typedef struct HeapType
{
	int			maxCount;
	int			currentCount;
	HeapNode	*pData;
}				ArrayMaxHeap, ArrayMinHeap;

ArrayMinHeap	*createMinHeap(int maxCount);
void			deleteMinHeap(ArrayMinHeap *heap);
int				insertMinHeap(ArrayMinHeap *heap, HeapNode data);
HeapNode 		*removeMinHeap(ArrayMinHeap *heap); // remove heap's root node and return removed root node
void			displayMinHeap(ArrayMinHeap *heap);

#define	TRUE		1
#define	FALSE		0
#define	ERROR		-1

#endif