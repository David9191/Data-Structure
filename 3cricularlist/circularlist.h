#ifndef _CIRCULAR_
#define _CIRCULAR_

// malloc
#include <stdlib.h>
// printf
#include <stdio.h>
// memset
#include <string.h>

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType *pLink;
} CircularListNode;

typedef struct LinkedListType
{
	int	currentElementCount;	// 현재 저장된 원소의 개수
	CircularListNode headerNode;		// 헤더 노드(Header Node)
} CircularList;

CircularList		*createLinkedList(void);
int					addFirstElement(CircularList *pList, CircularListNode *new);
int 		        addLLElement(CircularList *pList, int position, CircularListNode element);
int 		        removeLLElement(CircularList *pList, int position);
void		        displayLinkedList(CircularList *pList);
CircularListNode	*getLLElement(CircularList *pList, int position);
int			        getLinkedListLength(CircularList *pList);

void        	    clearLinkedList(CircularList *pList);
void                deleteLinkedList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
