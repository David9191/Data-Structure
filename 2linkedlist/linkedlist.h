#ifndef _LINKEDLIST_
#define _LINKEDLIST_

// malloc
#include <stdlib.h>
// printf
#include <stdio.h>
// memset
#include <string.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int	currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList	*createLinkedList(void);
int 		addLLElement(LinkedList* pList, int position, ListNode element);
int 		removeLLElement(LinkedList* pList, int position);
void		displayLinkedList(LinkedList* pList);
ListNode	*getLLElement(LinkedList* pList, int position);
int			getLinkedListLength(LinkedList* pList);

void 		clearLinkedList(LinkedList* pList);
void		deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif