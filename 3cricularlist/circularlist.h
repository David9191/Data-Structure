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
	int	currentElementCount;		// 현재 저장된 원소의 개수
	CircularListNode headerNode;	// 헤더 노드(Header Node)
} CircularList;

CircularList		*createCircularList(void);
int					addFirstElement(CircularList *pList, CircularListNode *new);
int 		        addCLElement(CircularList *pList, int position, CircularListNode element);
int 		        removeCLElement(CircularList *pList, int position);
CircularListNode	*getCLElement(CircularList *pList, int position);
void		        displayCircularList(CircularList *pList);
int			        getCircularListLength(CircularList *pList);

void        	    clearCircularList(CircularList *pList);
void                deleteCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
